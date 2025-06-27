#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    this->brain = new Brain();
    std::cout << "[Cat] Default constructor" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type) {
    this->brain = new Brain();
    std::cout << "[Cat] Constructor with params" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    this->brain = new Brain(*other.brain);
    std::cout << "[Cat] Copy constructor" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "[Cat] Destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}


void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
