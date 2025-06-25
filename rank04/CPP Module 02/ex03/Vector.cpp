#include "Vector.hpp"

Vector::Vector() :
    start_(Point(0, 0)),
    end_(Point(0, 0)),
    x_vector_(0.0f),
    y_vector_(0.0f) {}

Vector::Vector(const Point start, const Point end) :
    start_(start),
    end_(end),
    x_vector_(end.getX() - start.getX()),
    y_vector_(end.getY() - start.getY()) {}

Vector::Vector(const Vector& other) : 
    start_(other.start_),
    end_(other.end_),
    x_vector_(other.x_vector_),
    y_vector_(other.y_vector_) {}

Vector::~Vector() {}

Vector& Vector::operator=(const Vector& other) {
    (void)other;
    return *this;
}

Fixed Vector::crossProduct(const Vector& other) const {
    return x_vector_ * other.y_vector_ - y_vector_ * other.x_vector_;
}
