#include "Span.hpp"
#include <algorithm>

Span::Span() : max_size_(0) {}

Span::Span(unsigned int N) : max_size_(N) {}

Span::Span(const Span& other) : numbers_(other.numbers_), max_size_(other.max_size_) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers_ = other.numbers_;
        max_size_ = other.max_size_;
    }
    return *this;
}

const char* Span::FullException::what() const throw() {
    return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to compute span";
}


void Span::addNumber(int number) {
    if (numbers_.size() >= max_size_) {
        throw FullException();
    }
    numbers_.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers_.size() < 2) {
        throw NotEnoughNumbersException();
    }

    std::vector<int> copy(numbers_);
    std::sort(copy.begin(), copy.end());

    unsigned int min_diff
        = static_cast<unsigned int>(copy[1])
        - static_cast<unsigned int>(copy[0]);
    for (size_t i = 2; i < copy.size(); ++i) {
        unsigned int diff
            = static_cast<unsigned int>(copy[i])
            - static_cast<unsigned int>(copy[i - 1]);
        if (diff < min_diff) min_diff = diff;
    }
    return min_diff;
}


unsigned int Span::longestSpan() const {
    if (numbers_.size() < 2) {
        throw NotEnoughNumbersException();
    }

    int min = *std::min_element(numbers_.begin(), numbers_.end());
    int max = *std::max_element(numbers_.begin(), numbers_.end());

    return static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
}
