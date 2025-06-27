#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    this->brain = new Brain();
    std::cout << "[Dog] Default constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    this->brain = new Brain();
    std::cout << "[Dog] Constructor with params" << std::endl;
}

Dog::Dog(const Dog& other) {
    this->brain = new Brain(*other.brain);
    std::cout << "[Dog] Copy constructor" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "[Dog] Destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}


void Dog::makeSound() const {
    std::cout << "Bow wow!" << std::endl;
}
