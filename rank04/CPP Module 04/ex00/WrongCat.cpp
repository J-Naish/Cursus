#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "[WrongCat] Default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout << "[WrongCat] Constructor with params" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] Copy constructor" << std::endl;
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}


void WrongCat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
