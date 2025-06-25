#pragma once
#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {

    private:

        const Fixed x_;
        const Fixed y_;

    public:

        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        ~Point();

        Point& operator=(const Point& other);

};


#endif