#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* array, const size_t length, F f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif
