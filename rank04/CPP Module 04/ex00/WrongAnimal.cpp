#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "[WrongAnimal] Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
    std::cout << "[WrongAnimal] Constructor with params" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] Copy constructor" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
void WrongAnimal::setType(std::string type) {
    this->type = type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal Sound" << std::endl;
}
