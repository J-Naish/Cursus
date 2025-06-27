#include "Animal.hpp"

Animal::Animal() {
    std::cout << "[Animal] Default constructor" << std::endl;
}

Animal::Animal(std::string type) {
    std::cout << "[Animal] Constructor with params" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal& other) {
    std::cout << "[Animal] Copy constructor" << std::endl;
    *this = other;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}
void Animal::setType(std::string type) {
    this->type = type;
}

void Animal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
}
