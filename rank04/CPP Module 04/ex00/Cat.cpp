#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "[Cat] Default constructor" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "[Cat] Constructor with params" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "[Cat] Copy constructor" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}


void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
