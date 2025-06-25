#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->value = (value << Fixed::FRACTIONAL_BITS);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (Fixed::ONE));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->value;
}

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
}

float Fixed::toFloat( void ) const {
    return (float)this->value / (float)(Fixed::ONE);
}

int Fixed::toInt( void ) const {
    return roundf(this->value / (Fixed::ONE));
}

std::ostream& operator<<(std::ostream& out, Fixed const& value) {
    out << value.toFloat();
    return out;
}
