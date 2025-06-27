#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog] Default constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "[Dog] Constructor with params" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "[Dog] Copy constructor" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}


void Dog::makeSound() const {
    std::cout << "Bow wow!" << std::endl;
}
