#include "Circle.h"
#include "MyExcpetions.h"
#include "Display.h"

void Circle::draw()
{
    display->drawCircle(r);
}

Circle::Circle(Display *w, int r) : Shape(w)
{
    if (r < 0)
    {
        throw MyExcpetions();
    }
    this->r = r;
}
