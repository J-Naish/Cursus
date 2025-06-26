#include "Vector.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    const Vector ab = Vector(a, b);
    const Vector bc = Vector(b, c);
    const Vector ca = Vector(c, a);

    const Vector ap = Vector(a, point);
    const Vector bp = Vector(b, point);
    const Vector cp = Vector(c, point);


    Fixed cross1 = Vector::crossProduct(ab, ap);
    Fixed cross2 = Vector::crossProduct(bc, bp);
    Fixed cross3 = Vector::crossProduct(ca, cp);


    return (cross1 > 0 && cross2 > 0 && cross3 > 0) ||
            (cross1 < 0 && cross2 < 0 && cross3 < 0);
}
