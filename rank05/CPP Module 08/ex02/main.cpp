#include "MutantStack.hpp"

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <string>

namespace {

void print_section(const std::string& title) {
    std::cout << std::endl << "=== " << title << " ===" << std::endl;
}

template <typename Container>
void print_forward(const Container& c, const std::string& label) {
    std::cout << label << ": [";
    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator ite = c.end();
    bool first = true;
    while (it != ite) {
        if (!first) std::cout << ", ";
        std::cout << *it;
        first = false;
        ++it;
    }
    std::cout << "]" << std::endl;
}

}

int main(void) {

    print_section("subject example: MutantStack");
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << "top  = " << mstack.top()  << "  (expect 17)" << std::endl;

        mstack.pop();
        std::cout << "size = " << mstack.size() << "  (expect 1)"  << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it  = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "iteration: ";
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        std::stack<int> s(mstack);
        std::cout << "std::stack<int> s(mstack) compiled OK; s.size() = "
                  << s.size() << std::endl;
    }

    print_section("subject example replaced with std::list");
    {
        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "top  = " << mstack.back() << "  (expect 17)" << std::endl;

        mstack.pop_back();
        std::cout << "size = " << mstack.size() << "  (expect 1)"  << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it  = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "iteration: ";
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }

    print_section("inherited stack ops still work");
    {
        MutantStack<int> ms;
        std::cout << "empty()? " << (ms.empty() ? "yes" : "no") << "  (expect yes)" << std::endl;

        ms.push(10);
        ms.push(20);
        ms.push(30);
        std::cout << "size = " << ms.size() << "  (expect 3)"  << std::endl;
        std::cout << "top  = " << ms.top()  << "  (expect 30)" << std::endl;

        ms.pop();
        std::cout << "size = " << ms.size() << "  (expect 2)"  << std::endl;
        std::cout << "top  = " << ms.top()  << "  (expect 20)" << std::endl;
    }

    print_section("forward iteration: bottom-to-top order");
    {
        MutantStack<int> ms;
        ms.push(1);
        ms.push(2);
        ms.push(3);
        ms.push(4);
        print_forward(ms, "ms (push 1..4)");
    }

    print_section("empty stack: begin == end");
    {
        MutantStack<int> ms;
        if (ms.begin() == ms.end()) {
            std::cout << "begin == end on empty stack: OK" << std::endl;
        } else {
            std::cout << "FAIL: begin != end on empty stack" << std::endl;
        }
    }

    print_section("const MutantStack: const_iterator works");
    {
        MutantStack<int> tmp;
        tmp.push(100);
        tmp.push(200);
        tmp.push(300);

        const MutantStack<int> cms(tmp);

        MutantStack<int>::const_iterator it  = cms.begin();
        MutantStack<int>::const_iterator ite = cms.end();
        std::cout << "const iter: ";
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
        // *it = 999;  // would not compile (const_iterator)
    }

    print_section("STL algorithm: std::find through MutantStack");
    {
        MutantStack<int> ms;
        ms.push(11);
        ms.push(22);
        ms.push(33);
        ms.push(44);

        MutantStack<int>::iterator found = std::find(ms.begin(), ms.end(), 33);
        if (found != ms.end()) {
            std::cout << "found 33: " << *found << std::endl;
        } else {
            std::cout << "FAIL: 33 not found" << std::endl;
        }

        MutantStack<int>::iterator notfound = std::find(ms.begin(), ms.end(), 999);
        if (notfound == ms.end()) {
            std::cout << "999 not found (expected)" << std::endl;
        } else {
            std::cout << "FAIL: 999 should not be found" << std::endl;
        }
    }

    print_section("iterator arithmetic: deque is RandomAccess");
    {
        MutantStack<int> ms;
        ms.push(1);
        ms.push(2);
        ms.push(3);
        ms.push(4);
        ms.push(5);

        MutantStack<int>::iterator it = ms.begin();
        std::cout << "it[0]   = " << it[0]    << std::endl;
        std::cout << "it[2]   = " << it[2]    << std::endl;
        std::cout << "*(it+3) = " << *(it+3)  << std::endl;
        std::cout << "distance(begin,end) = "
                  << (ms.end() - ms.begin()) << "  (expect 5)" << std::endl;
    }

    print_section("OCF: copy constructor + deep copy");
    {
        MutantStack<int> a;
        a.push(1);
        a.push(2);
        a.push(3);

        MutantStack<int> b(a);
        print_forward(a, "a");
        print_forward(b, "b (copy of a)");

        b.push(99);
        print_forward(a, "a (must be unchanged: 1,2,3)");
        print_forward(b, "b (must be 1,2,3,99)");
    }

    print_section("OCF: operator= + size change");
    {
        MutantStack<int> a;
        a.push(7);
        a.push(8);

        MutantStack<int> b;
        b.push(-1);
        b.push(-1);
        b.push(-1);
        b.push(-1);

        b = a;
        print_forward(a, "a (unchanged: 7,8)");
        print_forward(b, "b after b=a (must be 7,8)");

        a.push(999);
        print_forward(b, "b after a.push(999) (must still be 7,8)");
    }

    print_section("OCF: self-assignment");
    {
        MutantStack<int> a;
        a.push(10);
        a.push(20);
        a.push(30);

        MutantStack<int>& ref = a;
        a = ref;
        print_forward(a, "a after a=a (must be 10,20,30)");
    }

    print_section("custom type: MutantStack<std::string>");
    {
        MutantStack<std::string> ms;
        ms.push("alpha");
        ms.push("beta");
        ms.push("gamma");

        std::cout << "top = " << ms.top() << "  (expect gamma)" << std::endl;
        print_forward(ms, "ms");
    }

    print_section("MutantStack vs std::list output equivalence");
    {
        MutantStack<int> ms;
        ms.push(5);
        ms.push(17);
        ms.pop();
        ms.push(3);
        ms.push(5);
        ms.push(737);
        ms.push(0);

        std::list<int> ls;
        ls.push_back(5);
        ls.push_back(17);
        ls.pop_back();
        ls.push_back(3);
        ls.push_back(5);
        ls.push_back(737);
        ls.push_back(0);

        std::cout << "MutantStack: ";
        for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "std::list  : ";
        for (std::list<int>::iterator it = ls.begin(); it != ls.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "(outputs must match)" << std::endl;
    }

    print_section("upcast: passing MutantStack to std::stack constructor");
    {
        MutantStack<int> ms;
        ms.push(1);
        ms.push(2);
        ms.push(3);

        std::stack<int> s(ms);
        std::cout << "s.size() = " << s.size() << "  (expect 3)" << std::endl;
        std::cout << "s.top()  = " << s.top()  << "  (expect 3)" << std::endl;
    }

    std::cout << std::endl << "=== all tests done ===" << std::endl;
    return 0;
}
