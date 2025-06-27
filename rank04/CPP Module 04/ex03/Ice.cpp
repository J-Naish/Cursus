#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() {
    this->type_ = "ice";
}

Ice::Ice(const Ice& other) : AMateria("ice") {
    *this = other;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout <<
        "* shoots an ice bolt at " <<
        target.getName() <<
        " *" <<
        std::endl;
}
