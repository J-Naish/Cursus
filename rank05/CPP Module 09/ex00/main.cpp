#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstddef>
#include <cstdlib>

namespace {

    bool is_valid_date(const std::string& date) {
        if (date.size() != 10) return false;

        if (date[4] != '-' || date[7] != '-') return false;

        for (size_t i = 0; i < 10; i++) {
            if (i == 4 || i == 7) continue;
            if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
        }

        int m = std::atoi(date.substr(5, 2).c_str());
        int d = std::atoi(date.substr(8, 2).c_str());
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31) return false;

        return true;
    }

    bool parse_value(const std::string& s, double& out) {
        std::istringstream iss(s);
        iss >> out;
        if (iss.fail()) return false;
        char c;
        if (iss >> c) return false;
        return true;
    }

    void process_line(const std::string& line, const BitcoinExchange& btc) {
        if (line.empty()) return;

        std::string::size_type sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            return;
        }

        std::string date = line.substr(0, sep);
        std::string value_str = line.substr(sep + 3);

        if (!is_valid_date(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            return;
        }

        double value;
        if (!parse_value(value_str, value)) {
            std::cerr << "Error: bad input => " << value_str << std::endl;
            return;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            return;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            return;
        }

        try {
            double rate = btc.getRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } catch (const std::exception& e) {
            std::cerr<< "Error: " << e.what() << std::endl;
        }
    }

}


int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc("data.csv");

        std::ifstream input(argv[1]);
        if (!input.is_open()) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        std::string line;
        // skip header
        std::getline(input, line);

        while (std::getline(input, line)) {
            process_line(line, btc);
        }


    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
