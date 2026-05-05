#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe pm(argc, argv);
        pm.sort();
        pm.print();
    } catch(const std::exception&) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
