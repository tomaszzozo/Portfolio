#include "Triangle.h"

Triangle::Triangle(Display *w, int a1, int a2, int b1, int b2) : Shape(w)
{
    this->a1 = a1;
    this->a2 = a2;
    this->b1 = b1;
    this->b2 = b2;
}

void Triangle::draw()
{
    display->drawTriangle(a1, a2, b1, b2);
}


