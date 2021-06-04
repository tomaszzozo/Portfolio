#include "Shape.h"
#include "MyExcpetions.h"

Shape::Shape(Display* w)
{
    if (!w)
    {
        throw MyExcpetions();
    }
    display = w;
}

void Shape::changeDisplay(Display* newDisplay)
{
    if (!newDisplay)
    {
        throw MyExcpetions();
    }
    display = newDisplay;
}
