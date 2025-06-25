#include "Vector.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    const Vector ab = Vector(a, b);
    const Vector bc = Vector(b, c);
    const Vector ca = Vector(c, a);

    const Vector ap = Vector(a, point);
    const Vector bp = Vector(b, point);
    const Vector cp = Vector(c, point);


    Fixed cross1 = ab.crossProduct(ap);
    Fixed cross2 = bc.crossProduct(bp);
    Fixed cross3 = ca.crossProduct(cp);


    return (cross1 > 0 && cross2 > 0 && cross3 > 0) ||
            (cross1 < 0 && cross2 < 0 && cross3 < 0);
}
