#include "Cure.hpp"


Cure::Cure() {
    this->type_ = "cure";
}

Cure::Cure(const Cure& other) {
    *this = other;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout <<
        "* heals " <<
        target.getName() <<
        "’s wounds *" <<
        std::endl;
}
