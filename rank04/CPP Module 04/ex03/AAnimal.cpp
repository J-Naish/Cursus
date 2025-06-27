#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "[Animal] Default constructor" << std::endl;
}

AAnimal::AAnimal(std::string type) {
    std::cout << "[Animal] Constructor with params" << std::endl;
    this->type = type;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "[Animal] Copy constructor" << std::endl;
    *this = other;
}

AAnimal::~AAnimal() {
    std::cout << "[Animal] Destructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return this->type;
}
void AAnimal::setType(std::string type) {
    this->type = type;
}
