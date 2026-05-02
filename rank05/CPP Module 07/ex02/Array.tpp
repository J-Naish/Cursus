#pragma once
#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data_(new T[0]()), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data_(new T[n]()), size_(n) {}

template <typename T>
Array<T>::Array(const Array& other) : data_(new T[other.size_]()), size_(other.size_) {
    for (unsigned int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] data_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data_;
        data_ = new T[other.size_]();
        size_ = other.size_;
        for (unsigned int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size_) {
        throw Array::OutOfRange();
    }
    return data_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size_) {
        throw Array::OutOfRange();
    }
    return data_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

template <typename T>
const char* Array<T>::OutOfRange::what() const throw() {
    return "Index out of range";
}

#endif
