#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : rates_(other.rates_) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        rates_ = other.rates_;
    }
    return *this;
}


const char* BitcoinExchange::FileOpenException::what() const throw() {
    return "Could not open file";
}

const char* BitcoinExchange::DateOutOfRangeException::what() const throw() {
    return "Date is earlier than the database range.";
}


BitcoinExchange::BitcoinExchange(const std::string& database_path) {
    std::ifstream file(database_path.c_str());
    if (!file.is_open()) {
        throw FileOpenException();
    }

    std::string line;

    // skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {

        std::istringstream iss(line);
        std::string date;
        std::string rate_str;

        if (!std::getline(iss, date, ',')) continue;
        if (!std::getline(iss, rate_str)) continue;

        std::istringstream rss(rate_str);
        double rate;
        if (!(rss >> rate)) continue;

        rates_[date] = rate;
    }
}

double BitcoinExchange::getRate(const std::string& date) const {
    if (rates_.empty()) {
        throw DateOutOfRangeException();
    }

    std::map<std::string, double>::const_iterator it = rates_.find(date);
    if (it != rates_.end()) {
        return it->second;
    }

    it = rates_.lower_bound(date);
    if (it == rates_.begin()) {
        throw DateOutOfRangeException();
    }
    --it;
    return it->second;
}
