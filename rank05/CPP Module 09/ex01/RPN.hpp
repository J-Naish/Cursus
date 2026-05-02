#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <string>

class RPN {

    public:

        class InvalidExpressionException : public std::exception {
            public:
                const char* what() const throw();
        };

        class DivisionByZeroException : public std::exception {
            public:
                const char* what() const throw();
        };

        static int evaluate(const std::string& expression);


    private:
        RPN();
        RPN(const RPN& other);
        ~RPN();
        RPN& operator=(const RPN& other);

};

#endif
