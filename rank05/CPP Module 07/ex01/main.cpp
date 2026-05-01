#include "iter.hpp"

#include <cctype>
#include <iostream>
#include <string>

template <typename T>
void print(T const& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x) {
    ++x;
}

void shout(std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
    }
}

int main(void) {

    std::cout << "=== int array: read-only via function template (const T&) ===" << std::endl;
    {
        int arr[] = {1, 2, 3, 4, 5};
        size_t const n = sizeof(arr) / sizeof(arr[0]);
        iter(arr, n, ::print<int>);
        std::cout << std::endl;
    }

    std::cout << "=== int array: in-place modify (T&) ===" << std::endl;
    {
        int arr[] = {10, 20, 30};
        size_t const n = sizeof(arr) / sizeof(arr[0]);

        std::cout << "before: ";
        iter(arr, n, ::print<int>);
        std::cout << std::endl;

        iter(arr, n, ::increment<int>);

        std::cout << "after : ";
        iter(arr, n, ::print<int>);
        std::cout << std::endl;
    }

    std::cout << "=== const int array: must accept const elements ===" << std::endl;
    {
        const int arr[] = {7, 8, 9};
        size_t const n = sizeof(arr) / sizeof(arr[0]);
        iter(arr, n, ::print<int>);
        std::cout << std::endl;
    }

    std::cout << "=== double array ===" << std::endl;
    {
        double arr[] = {1.1, 2.2, 3.3};
        size_t const n = sizeof(arr) / sizeof(arr[0]);
        iter(arr, n, ::print<double>);
        std::cout << std::endl;
    }

    std::cout << "=== std::string array: non-template free function ===" << std::endl;
    {
        std::string arr[] = {"hello", "world", "foo"};
        size_t const n = sizeof(arr) / sizeof(arr[0]);

        std::cout << "before: ";
        iter(arr, n, ::print<std::string>);
        std::cout << std::endl;

        iter(arr, n, shout);

        std::cout << "after : ";
        iter(arr, n, ::print<std::string>);
        std::cout << std::endl;
    }

    std::cout << "=== empty array: length 0 must be a no-op ===" << std::endl;
    {
        int arr[1] = {0};
        std::cout << "(no output expected): ";
        iter(arr, 0, ::print<int>);
        std::cout << "[done]" << std::endl;
    }

    return 0;
}
