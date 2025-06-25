#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "Point.hpp"


class Vector {

    public:

        Vector();
        Vector(const Point start, const Point end);
        Vector(const Vector& other);
        ~Vector();

        Vector& operator=(const Vector& other);

        Fixed crossProduct(const Vector& other) const;

    private:

        const Point start_;
        const Point end_;

        const Fixed x_vector_;
        const Fixed y_vector_;

};


#endif