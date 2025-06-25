#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

    public:

        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed& operator=(const Fixed& other);

        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;

        Fixed operator+(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

        static Fixed& min(Fixed& f1, Fixed& f2);
        static const Fixed& min(const Fixed& f1, const Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static const Fixed& max(const Fixed& f1, const Fixed& f2);

    private:

        int _raw_bits;
        static const int FRACTIONAL_BITS = 8;
        static const int ONE = 1 << FRACTIONAL_BITS;

};


std::ostream& operator<<(std::ostream& out, Fixed const& f);

#endif
