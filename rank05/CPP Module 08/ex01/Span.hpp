#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span {

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);


        void addNumber(int number);

        template <typename InputIt>
        void addRange(InputIt first, InputIt last);

        unsigned int shortestSpan() const;

        unsigned int longestSpan() const;


        class FullException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Span is full";
                }
        };

        class NotEnoughNumbersException: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Not enough numbers to compute span";
                }
        };


    private:
        std::vector<int> numbers_;
        unsigned int max_size_;

};


template <typename InputIt>
void Span::addRange(InputIt first, InputIt last) {
    typename std::iterator_traits<InputIt>::difference_type length
        = std::distance(first, last);

    if (numbers_.size() + static_cast<unsigned int>(length) > max_size_) {
        throw FullException();
    }

    numbers_.insert(numbers_.end(), first, last);
}

#endif
