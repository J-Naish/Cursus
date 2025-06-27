#include "AMateria.hpp"


AMateria::AMateria() {
    this->type_ = "Unknown";
}

AMateria::AMateria(std::string const & type) {
    this->type_ = type;
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return this->type_;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "[virtual function] " << this->type_ << " is being used" << std::endl;
}
