#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point& other) {
    *this = other;
}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

Fixed Point::getX() const {
    return x_;
}

Fixed Point::getY() const {
    return y_;
}
