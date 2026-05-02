#include "RPN.hpp"
#include <string>
#include <sstream>
#include <cctype>
#include <stack>

namespace {

    bool is_operand(const std::string& token) {
        return token.size() == 1 && std::isdigit(token[0]);
    }

    bool is_operator(const std::string& token) {
        if (token.size() != 1) return false;
        return token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*';
    }

    int operate(int a, int b, char t) {
        if (t == '+')
            return a + b;
        if (t == '-')
            return a - b;
        if (t == '/') {
            if (b == 0) throw RPN::DivisionByZeroException();
            return a / b;
        }
        if (t == '*')
            return a * b;

        throw RPN::InvalidExpressionException();
    }
}

const char* RPN::InvalidExpressionException::what() const throw() {
    return "invalid expression";
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "division by zero";
}


RPN::RPN() {}

RPN::RPN(const RPN&) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN&) {
    return *this;
}


int RPN::evaluate(const std::string& expression) {
    std::stack<int> s;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (is_operand(token)) {
            s.push(token[0] - '0');
        } else if (is_operator(token)) {
            if (s.size() < 2) throw InvalidExpressionException();
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(operate(a, b, token[0]));
        } else {
            throw InvalidExpressionException();
        }
    }

    if (s.size() != 1) throw InvalidExpressionException();
    return s.top();
}
