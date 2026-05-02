#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

class BitcoinExchange {

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& other);

        explicit BitcoinExchange(const std::string& path);

        double getRate(const std::string& date) const;

        class FileOpenException: public std::exception {
            public:
                const char* what() const throw();
        };

        class DateOutOfRangeException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:

        std::map<std::string, double> rates_;

};



#endif
