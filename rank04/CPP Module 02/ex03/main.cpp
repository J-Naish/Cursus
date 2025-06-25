#include <iostream>
#include "bsp.hpp"
#include "Point.hpp"
#include "Vector.hpp"

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef RESET
#  define RESET "\033[0m"
# endif


static void test(
    const Point& a,
    const Point& b,
    const Point &c,
    const float& px,
    const float& py
) {

    Point p(px, py);

    std::cout << "(" << px << "," << py << ")"
        << " is " << GREEN << (bsp(a, b, c, p) ? "inside" : "not inside") << RESET << " the triangle" << std::endl;
}

int main( void ) {

    Point a(0.0f, 0.0f);
    Point b(3.0f, 0.0f);
    Point c(1.5f, 3.0f);

    test(a, b, c, 1.5f, 1.0f); // should be inside
    test(a, b, c, 5.0f, 5.0f); // should not be inside
    test(a, b, c, 1.5f, 0.0f); // should not be inside (on the side ab)
    test(a, b, c, 0.0f, 0.0f); // should not be inside (on the edge a)

    return 0;
}
