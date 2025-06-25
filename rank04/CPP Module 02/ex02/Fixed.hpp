#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

    public:

        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

    private:

        int value;
        static const int FRACTIONAL_BITS = 8;
        static const int ONE = 1 << FRACTIONAL_BITS;

};


std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif
