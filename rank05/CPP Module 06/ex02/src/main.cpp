#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base* generate(void) {
    int r = std::rand() % 3;

    if (r == 0) {
        return new A();
    } else if (r == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "null pointer" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
        return;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
        return;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
        return;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}

int main() {

    std::srand(static_cast<unsigned>(std::time(NULL)));

    std::cout << "=== random generation (5 trials) ===" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Base* obj = generate();

        std::cout << "trial " << i << ": ";
        std::cout << "[ptr] ";
        identify(obj);
        std::cout << "         [ref] ";
        identify(*obj);

        delete obj;
    }

    std::cout << std::endl;
    std::cout << "=== direct instantiation ===" << std::endl;
    {
        A a;
        B b;
        C c;

        std::cout << "A: [ptr] ";
        identify(&a);
        std::cout << "   [ref] ";
        identify(a);

        std::cout << "B: [ptr] ";
        identify(&b);
        std::cout << "   [ref] ";
        identify(b);

        std::cout << "C: [ptr] ";
        identify(&c);
        std::cout << "   [ref] ";
        identify(c);
    }

    std::cout << std::endl;
    std::cout << "=== null pointer ===" << std::endl;
    std::cout << "[ptr] ";
    identify(static_cast<Base*>(NULL));

    return 0;
}
