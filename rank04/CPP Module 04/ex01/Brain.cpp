#include "Brain.hpp"


Brain::Brain() {
    std::cout << "[Brain] Default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Copy constructor" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < kSize; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

