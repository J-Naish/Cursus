#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();
        Array& operator=(const Array& other);

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size() const;

        // exceptions
        class OutOfRange : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        T* data_;
        unsigned int size_;
};

#include "Array.tpp"

#endif
