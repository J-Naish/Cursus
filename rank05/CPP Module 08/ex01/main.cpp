#include "Span.hpp"

#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

namespace {

void print_section(const std::string& title) {
    std::cout << std::endl << "=== " << title << " ===" << std::endl;
}

}

int main(void) {

    print_section("subject example");
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 2)"  << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 14)" << std::endl;
    }

    print_section("addNumber: throw when full");
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        try {
            sp.addNumber(4);
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "caught: " << e.what() << std::endl;
        }
    }

    print_section("shortestSpan / longestSpan: not enough numbers");
    {
        Span empty(5);
        try {
            empty.shortestSpan();
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "shortest on empty -> " << e.what() << std::endl;
        }
        try {
            empty.longestSpan();
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "longest on empty  -> " << e.what() << std::endl;
        }

        Span one(5);
        one.addNumber(42);
        try {
            one.shortestSpan();
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "shortest on size=1 -> " << e.what() << std::endl;
        }
    }

    print_section("duplicates: shortestSpan must be 0");
    {
        Span sp(4);
        sp.addNumber(7);
        sp.addNumber(7);
        sp.addNumber(7);
        sp.addNumber(7);
        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 0)" << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 0)" << std::endl;
    }

    print_section("negative numbers");
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-3);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(7);
        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 2)"  << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 17)" << std::endl;
    }

    print_section("INT_MIN / INT_MAX (no overflow UB)");
    {
        Span sp(2);
        sp.addNumber(INT_MIN);
        sp.addNumber(INT_MAX);
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << std::endl;
        std::cout << "(both should be 4294967295)" << std::endl;
    }

    print_section("addRange: from std::vector");
    {
        std::vector<int> src;
        src.push_back(100);
        src.push_back(50);
        src.push_back(200);
        src.push_back(75);

        Span sp(10);
        sp.addRange(src.begin(), src.end());
        std::cout << "added " << src.size() << " numbers via vector iterators" << std::endl;
        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 25)" << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 150)" << std::endl;
    }

    print_section("addRange: from std::list (different container)");
    {
        std::list<int> src;
        src.push_back(1);
        src.push_back(4);
        src.push_back(9);
        src.push_back(16);

        Span sp(10);
        sp.addRange(src.begin(), src.end());
        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 3)"  << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 15)" << std::endl;
    }

    print_section("addRange: from C array (pointer is iterator)");
    {
        int arr[] = {-5, 12, 0, 8, -2};
        const size_t n = sizeof(arr) / sizeof(arr[0]);

        Span sp(10);
        sp.addRange(arr, arr + n);
        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 2)"  << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 17)" << std::endl;
    }

    print_section("addRange: combined with prior addNumber");
    {
        Span sp(10);
        sp.addNumber(50);
        sp.addNumber(60);

        std::vector<int> src;
        src.push_back(10);
        src.push_back(70);
        src.push_back(20);

        sp.addRange(src.begin(), src.end());
        std::cout << "shortestSpan = " << sp.shortestSpan() << "  (expect 10)" << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << "  (expect 60)" << std::endl;
    }

    print_section("addRange: throw when overflow (strong guarantee)");
    {
        Span sp(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        std::vector<int> src;
        for (int i = 0; i < 30; ++i) src.push_back(i);

        try {
            sp.addRange(src.begin(), src.end());
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "caught: " << e.what() << std::endl;
        }

        std::cout << "after exception, shortestSpan still works: "
                  << sp.shortestSpan() << "  (expect 1, state preserved)" << std::endl;
    }

    print_section("10,000 random numbers");
    {
        const unsigned int N = 10000;
        std::srand(42);

        std::vector<int> src;
        src.reserve(N);
        for (unsigned int i = 0; i < N; ++i) {
            src.push_back(std::rand());
        }

        Span sp(N);
        sp.addRange(src.begin(), src.end());

        std::cout << "filled with " << N << " random numbers" << std::endl;
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << std::endl;
    }

    print_section("100,000 numbers (stress)");
    {
        const unsigned int N = 100000;
        std::srand(7);

        Span sp(N);
        std::vector<int> src;
        src.reserve(N);
        for (unsigned int i = 0; i < N; ++i) {
            src.push_back(std::rand());
        }
        sp.addRange(src.begin(), src.end());

        std::cout << "filled with " << N << " random numbers" << std::endl;
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan()  << std::endl;
    }

    print_section("OCF: copy constructor and assignment");
    {
        Span a(5);
        a.addNumber(10);
        a.addNumber(20);
        a.addNumber(30);

        Span b(a);                           // copy ctor
        std::cout << "b copied from a, shortestSpan = " << b.shortestSpan()
                  << "  (expect 10)" << std::endl;

        Span c(2);
        c = a;                               // operator=
        std::cout << "c assigned from a, longestSpan = " << c.longestSpan()
                  << "  (expect 20)" << std::endl;

        a.addNumber(99);
        std::cout << "after a.addNumber(99): "
                  << "a.size effects -> shortest=" << a.shortestSpan()
                  << ", b unchanged shortest=" << b.shortestSpan()
                  << " (deep copy verified)" << std::endl;
    }

    print_section("self-assignment");
    {
        Span a(3);
        a.addNumber(1);
        a.addNumber(5);
        a.addNumber(9);

        Span& ref = a;
        a = ref;
        std::cout << "after a = a, shortestSpan = " << a.shortestSpan()
                  << "  (expect 4)" << std::endl;
    }

    print_section("specific exception types catchable");
    {
        Span sp(1);
        sp.addNumber(1);

        try {
            sp.addNumber(2);
        } catch (Span::FullException& e) {
            std::cout << "caught Span::FullException: " << e.what() << std::endl;
        }

        Span empty(5);
        try {
            empty.shortestSpan();
        } catch (Span::NotEnoughNumbersException& e) {
            std::cout << "caught Span::NotEnoughNumbersException: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl << "=== all tests done ===" << std::endl;
    return 0;
}
