#include "Fixed.hpp"

Fixed::Fixed() : raw_bits_(0) {}

Fixed::Fixed(const int value) {
    this->raw_bits_ = (value << Fixed::kFractionalBits);
}

Fixed::Fixed(const float value) {
    this->raw_bits_ = roundf(value * Fixed::kOne);
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& other) {
    this->raw_bits_ = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& rhs) const {
    return this->raw_bits_ > rhs.raw_bits_;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->raw_bits_ < rhs.raw_bits_;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->raw_bits_ >= rhs.raw_bits_;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->raw_bits_ <= rhs.raw_bits_;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->raw_bits_ == rhs.raw_bits_;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->raw_bits_ != rhs.raw_bits_;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->raw_bits_ + rhs.raw_bits_);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->raw_bits_ - rhs.raw_bits_);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((this->raw_bits_ * rhs.raw_bits_) >> Fixed::kFractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((this->raw_bits_ << Fixed::kFractionalBits) / rhs.raw_bits_);
    return result;
}

Fixed& Fixed::operator++() {
    this->raw_bits_++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed result(*this);
    this->raw_bits_++;
    return result;
}

Fixed& Fixed::operator--() {
    this->raw_bits_--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed result(*this);
    this->raw_bits_--;
    return result;
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

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
    if (f1 <= f2) {
        return f1;
    } else {
        return f2;
    }
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
    if (f1 <= f2) {
        return f1;
    } else {
        return f2;
    }
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
    if (f1 >= f2) {
        return f1;
    } else {
        return f2;
    }
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
    if (f1 >= f2) {
        return f1;
    } else {
        return f2;
    }
}
