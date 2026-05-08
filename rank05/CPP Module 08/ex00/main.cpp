#include "easyfind.hpp"

#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

namespace {

    template <typename T>
    void print_container(const T& c, const std::string& label) {
        std::cout << label << ": [";
        for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
            if (it != c.begin()) std::cout << ", ";
            std::cout << *it;
        }
        std::cout << "]" << std::endl;
    }

}

int main(void) {

    std::cout << "=== std::vector<int>: found ===" << std::endl;
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        print_container(v, "v");

        try {
            std::vector<int>::iterator it = easyfind(v, 30);
            std::cout << "found 30 at index " << (it - v.begin())
                      << " (value=" << *it << ")" << std::endl;
        } catch (std::exception& e) {
            std::cout << "FAIL: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== std::vector<int>: not found -> throw ===" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        try {
            easyfind(v, 999);
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "caught: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== std::vector<int>: empty -> throw ===" << std::endl;
    {
        std::vector<int> v;

        try {
            easyfind(v, 0);
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "caught: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== std::vector<int>: returns first occurrence ===" << std::endl;
    {
        std::vector<int> v;
        v.push_back(7);
        v.push_back(7);
        v.push_back(7);
        print_container(v, "v");

        try {
            std::vector<int>::iterator it = easyfind(v, 7);
            std::cout << "first 7 at index " << (it - v.begin())
                      << " (must be 0)" << std::endl;
        } catch (std::exception& e) {
            std::cout << "FAIL: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== mutation via returned iterator ===" << std::endl;
    {
        std::vector<int> v;
        v.push_back(100);
        v.push_back(200);
        v.push_back(300);
        print_container(v, "before");

        try {
            std::vector<int>::iterator it = easyfind(v, 200);
            *it = 999;
            print_container(v, "after *it=999");
        } catch (std::exception& e) {
            std::cout << "FAIL: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== std::list<int>: works on non-random-access container ===" << std::endl;
    {
        std::list<int> l;
        l.push_back(5);
        l.push_back(15);
        l.push_back(25);
        print_container(l, "l");

        try {
            std::list<int>::iterator it = easyfind(l, 15);
            std::cout << "found 15 (value=" << *it << ")" << std::endl;
        } catch (std::exception& e) {
            std::cout << "FAIL: " << e.what() << std::endl;
        }

        try {
            easyfind(l, 42);
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "caught: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== std::deque<int> ===" << std::endl;
    {
        std::deque<int> d;
        d.push_back(-1);
        d.push_back(0);
        d.push_back(1);
        print_container(d, "d");

        try {
            std::deque<int>::iterator it = easyfind(d, 0);
            std::cout << "found 0 (value=" << *it << ")" << std::endl;
        } catch (std::exception& e) {
            std::cout << "FAIL: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== specific exception type catchable ===" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);

        try {
            easyfind(v, 999);
        } catch (std::out_of_range& e) {
            std::cout << "caught std::out_of_range specifically: " << e.what() << std::endl;
        } catch (std::exception& e) {
            std::cout << "FAIL: caught only as std::exception: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== all tests done ===" << std::endl;
    return 0;
}
