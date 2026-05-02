#include "Array.hpp"

#include <exception>
#include <iostream>
#include <string>

namespace {

template <typename T>
void print_array(const Array<T>& arr, const std::string& label) {
    std::cout << label << " (size=" << arr.size() << "): [";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << arr[i];
    }
    std::cout << "]" << std::endl;
}

}

int main(void) {

    std::cout << "=== subject hint: new int() vs new int ===" << std::endl;
    {
        int* a = new int();
        int* b = new int;
        std::cout << "*a (new int())  = " << *a << "  (must be 0)" << std::endl;
        std::cout << "*b (new int)    = " << *b << "  (uninitialized: any value)" << std::endl;
        delete a;
        delete b;
    }

    std::cout << std::endl;
    std::cout << "=== default construction (empty) ===" << std::endl;
    {
        Array<int> a;
        std::cout << "size = " << a.size() << "  (must be 0)" << std::endl;
        try {
            a[0];
            std::cout << "FAIL: no exception" << std::endl;
        } catch (std::exception& e) {
            std::cout << "[0] on empty -> caught: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== sized construction: value-initialized ===" << std::endl;
    {
        Array<int>          ai(4);
        Array<double>       ad(3);
        Array<std::string>  as(3);

        print_array(ai, "Array<int>(4)");
        print_array(ad, "Array<double>(3)");
        print_array(as, "Array<string>(3)");
    }

    std::cout << std::endl;
    std::cout << "=== element assignment via operator[] ===" << std::endl;
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); ++i) {
            a[i] = static_cast<int>(i * i);
        }
        print_array(a, "after a[i] = i*i");
    }

    std::cout << std::endl;
    std::cout << "=== copy constructor: deep copy independence ===" << std::endl;
    {
        Array<int> a(3);
        a[0] = 1; a[1] = 2; a[2] = 3;

        Array<int> b(a);
        b[0] = 100;

        print_array(a, "a (must be 1,2,3)");
        print_array(b, "b (must be 100,2,3)");
    }

    std::cout << std::endl;
    std::cout << "=== operator=: size change + deep copy ===" << std::endl;
    {
        Array<int> a(2);
        a[0] = 7; a[1] = 8;

        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); ++i) b[i] = -1;

        b = a;
        print_array(a, "a (unchanged: 7,8)");
        print_array(b, "b after b=a (must be 7,8)");

        a[0] = 999;
        print_array(b, "b after a[0]=999 (must still be 7,8)");
    }

    std::cout << std::endl;
    std::cout << "=== operator=: self-assignment ===" << std::endl;
    {
        Array<int> a(3);
        a[0] = 10; a[1] = 20; a[2] = 30;

        Array<int>& ref = a;     // alias to bypass -Wself-assign-overloaded
        a = ref;
        print_array(a, "a after a=a (must be 10,20,30)");
    }

    std::cout << std::endl;
    std::cout << "=== const Array: operator[] const works ===" << std::endl;
    {
        Array<int> tmp(3);
        tmp[0] = 11; tmp[1] = 22; tmp[2] = 33;
        const Array<int> ca(tmp);

        std::cout << "ca[0] = " << ca[0] << std::endl;
        std::cout << "ca[2] = " << ca[2] << std::endl;
        // ca[0] = 1;  // ← would not compile (operator[] const returns const T&)
    }

    std::cout << std::endl;
    std::cout << "=== range checks: boundaries ===" << std::endl;
    {
        Array<int> a(3);

        try { a[3]; std::cout << "FAIL at index 3" << std::endl; }
        catch (std::exception& e) { std::cout << "a[3]    -> " << e.what() << std::endl; }

        try { a[100]; std::cout << "FAIL at index 100" << std::endl; }
        catch (std::exception& e) { std::cout << "a[100]  -> " << e.what() << std::endl; }

        // (unsigned)-1 = UINT_MAX, should also throw
        try { a[static_cast<unsigned int>(-1)]; std::cout << "FAIL at -1" << std::endl; }
        catch (std::exception& e) { std::cout << "a[-1]   -> " << e.what() << std::endl; }
    }

    std::cout << std::endl;
    std::cout << "=== custom type: std::string deep copy ===" << std::endl;
    {
        Array<std::string> a(3);
        a[0] = "alpha";
        a[1] = "beta";
        a[2] = "gamma";

        Array<std::string> b = a;     // copy constructor
        b[0] = "ZZZ";

        print_array(a, "a");
        print_array(b, "b");
    }

    std::cout << std::endl;
    std::cout << "=== chain assignment ===" << std::endl;
    {
        Array<int> a(2), b(2), c(2);
        a[0] = 1; a[1] = 2;

        c = b = a;
        print_array(b, "b");
        print_array(c, "c");
    }

    std::cout << std::endl;
    std::cout << "=== all tests done ===" << std::endl;
    return 0;
}
