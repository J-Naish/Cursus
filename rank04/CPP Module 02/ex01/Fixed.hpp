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
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

    private:

        int raw_bits_;
        static const int kFractionalBits = 8;
        static const int kOne = 1 << kFractionalBits;

};


std::ostream& operator<<(std::ostream& out, Fixed const& f);

#endif
