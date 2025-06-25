#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->raw_bits = 0;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->raw_bits = (value << Fixed::FRACTIONAL_BITS);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->raw_bits = roundf(value * Fixed::ONE);
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw_bits = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& rhs) const {
    return this->raw_bits > rhs.raw_bits;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->raw_bits < rhs.raw_bits;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->raw_bits >= rhs.raw_bits;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->raw_bits <= rhs.raw_bits;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->raw_bits == rhs.raw_bits;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->raw_bits != rhs.raw_bits;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->raw_bits + rhs.raw_bits);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->raw_bits - rhs.raw_bits);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((this->raw_bits * rhs.raw_bits) >> Fixed::FRACTIONAL_BITS);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((this->raw_bits << Fixed::FRACTIONAL_BITS) / rhs.raw_bits);
    return result;
}

Fixed& Fixed::operator++() {
    this->raw_bits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed result(*this);
    this->raw_bits++;
    return result;
}

Fixed& Fixed::operator--() {
    this->raw_bits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed result(*this);
    this->raw_bits--;
    return result;
}

int Fixed::getRawBits( void ) const {
    return this->raw_bits;
}

void Fixed::setRawBits( int const raw ) {
    this->raw_bits = raw;
}

float Fixed::toFloat( void ) const {
    return (float)this->raw_bits / (float)Fixed::ONE;
}

int Fixed::toInt( void ) const {
    return roundf(this->raw_bits >> Fixed::FRACTIONAL_BITS);
}

std::ostream& operator<<(std::ostream& out, Fixed const& f) {
    out << f.toFloat();
    return out;
}
