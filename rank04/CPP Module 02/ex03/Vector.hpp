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

        static Fixed crossProduct(const Vector& v1, const Vector& v2);

    private:

        const Point start_;
        const Point end_;

        const Fixed x_vector_;
        const Fixed y_vector_;

};


#endif