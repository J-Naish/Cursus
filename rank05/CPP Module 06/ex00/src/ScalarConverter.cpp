#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

namespace {
    bool is_char(const std::string& s) {
        return s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
    }

    bool ends_with_f(const std::string& s) {
        return s.length() >= 1 && s[s.length() - 1] == 'f';
    }

    bool is_valid_int(const std::string& s) {
        std::stringstream ss(s);
        int tmp;
        ss >> tmp;
        return !ss.fail() && ss.eof();
    }

    bool is_valid_double(const std::string& s) {
        std::stringstream ss(s);
        double tmp;
        ss >> tmp;
        return !ss.fail() && ss.eof();
    }

    bool is_pseudo(const std::string& s) {
        return s == "nan" || s == "nanf"
            || s == "inff" || s == "+inff" || s == "-inff"
            || s == "inf" || s == "+inf" || s == "-inf";
    }

    double parse_double(const std::string& s) {
        std::stringstream ss(s);
        double v = 0.0;
        ss >> v;
        return v;
    }

    void print_as_char(double value) {
        std::cout << "char: ";
        if (std::isnan(value) || std::isinf(value)) {
            std::cout << "impossible" << std::endl;
        } else if (value < 0 || value > 127 ) {
            std::cout << "impossible" << std::endl;
        } else if (!std::isprint(static_cast<unsigned char>(value))) {
            std::cout << "Non displayable" << std::endl;
        } else {
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        }
    }

    void print_as_int(double value) {
        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value)) {
            std::cout << "impossible" << std::endl;
        } else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << static_cast<int>(value) << std::endl;
        }
    }

    void print_as_float(double value) {
        std::cout << "float: ";
        if (std::isnan(value)) {
            std::cout << "nanf" << std::endl;
        } else if (std::isinf(value) && value > 0) {
            std::cout << "+inff" << std::endl;
        } else if (std::isinf(value) && value < 0) {
            std::cout << "-inff" << std::endl;
        } else {
            if (value == std::floor(value)) {
                std::cout << std::fixed << std::setprecision(1) << value;
                std::cout.unsetf(std::ios::fixed);
            } else {
              std::cout << value;
            }
            std::cout << "f" << std::endl;
        }
    }

    void print_as_double(double value) {
        std::cout << "double: ";
        if (std::isnan(value)) {
            std::cout << "nan" << std::endl;
        } else if (std::isinf(value) && value > 0) {
            std::cout << "+inf" << std::endl;
        } else if (std::isinf(value) && value < 0) {
            std::cout << "-inf" << std::endl;
        } else {
            if (value == std::floor(value)) {
                std::cout << std::fixed << std::setprecision(1) << value;
                std::cout.unsetf(std::ios::fixed);
            } else {
              std::cout << value;
            }
            std::cout << std::endl;
        }
    }

}


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}


ScalarConverter::LiteralType ScalarConverter::detect_type(const std::string& literal) {

    if (literal.empty()) {
        return Invalid;
    }

    if (is_pseudo(literal)) {
        return Pseudo;
    }

    if (is_char(literal)) {
        return Char;
    }

    if (ends_with_f(literal)) {
        std::string body = literal.substr(0, literal.length() - 1);
        if (is_valid_double(body)) {
            return Float;
        }
    }

    if (literal.find_first_of(".eE") != std::string::npos) {
        if (is_valid_double(literal)) {
            return Double;
        }
    }

    if (is_valid_int(literal)) {
        return Int;
    }

    // handle overflow int like 2147483648(INT_MAX + 1) 
    if (is_valid_double(literal)) {
        return Double;
    }

    return Invalid;

}

void ScalarConverter::convert(const std::string& literal) {

    LiteralType type = detect_type(literal);
    double value = 0.0;

    switch (type) {
        case Invalid:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        case Pseudo:
            if (literal == "nan" || literal == "nanf") {
                value = std::numeric_limits<double>::quiet_NaN();
            } else if (literal == "-inf" || literal == "-inff") {
                value = -std::numeric_limits<double>::infinity();
            } else {
                value = std::numeric_limits<double>::infinity();
            }
            break;
        case Char:
            value = static_cast<double>(literal[0]);
            break;
        case Int:
        case Double:
            value = parse_double(literal);
            break;
        case Float: {
            std::string body = literal.substr(0, literal.length() - 1);
            value = parse_double(body);
            break;
        }
        default:
            break;
    }

    print_as_char(value);
    print_as_int(value);
    print_as_float(value);
    print_as_double(value);

}
