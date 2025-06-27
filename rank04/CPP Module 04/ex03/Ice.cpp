#include "Ice.hpp"


Ice::Ice() {
    this->type_ = "ice";
}

Ice::Ice(const Ice& other) {
    *this = other;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Ice* Ice::clone() {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout <<
        "* shoots an ice bolt at " <<
        target.getName() <<
        " *" <<
        std::endl;
}
