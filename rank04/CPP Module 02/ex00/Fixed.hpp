#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

    public:

        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:

        int raw_bits_;
        static const int kFractionalBits = 8;

};


#endif
