#include "whatever.hpp"

#include <iostream>
#include <string>

int main(void) {

    std::cout << "=== subject example (int) ===" << std::endl;
    {
        int a = 2;
        int b = 3;

        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== subject example (std::string) ===" << std::endl;
    {
        std::string c = "chaine1";
        std::string d = "chaine2";

        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== equal values: must return the second one ===" << std::endl;
    {
        int x = 7;
        int y = 7;
        std::cout << "x = " << x << ", y = " << y << std::endl;
        std::cout << "min returns &y? " << ((&::min(x, y) == &y) ? "yes" : "no") << std::endl;
        std::cout << "max returns &y? " << ((&::max(x, y) == &y) ? "yes" : "no") << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== works with double ===" << std::endl;
    {
        double a = 1.5;
        double b = -2.5;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap(a, b);
        std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== works with char ===" << std::endl;
    {
        char a = 'z';
        char b = 'a';
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    }

    return 0;
}
