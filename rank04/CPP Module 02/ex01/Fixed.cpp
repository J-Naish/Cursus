#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->raw_bits_ = 0;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->raw_bits_ = (value << Fixed::kFractionalBits);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->raw_bits_ = roundf(value * Fixed::kOne);
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw_bits_ = other.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->raw_bits_;
}

void Fixed::setRawBits( int const raw ) {
    this->raw_bits_ = raw;
}

float Fixed::toFloat( void ) const {
    return (float)this->raw_bits_ / (float)Fixed::kOne;
}

int Fixed::toInt( void ) const {
    return roundf(this->raw_bits_ >> Fixed::kFractionalBits);
}

std::ostream& operator<<(std::ostream& out, Fixed const& f) {
    out << f.toFloat();
    return out;
}
