#include "ComplexShape.h"
#include "MyExcpetions.h"

ComplexShape::ComplexShape(Display *w) : Shape(w){}

bool ComplexShape::add(Shape *o)
{
    if (!o)
    {
        throw MyExcpetions();
    }
    if (vec.size() < 5)
    {
        vec.push_back(o);
        return true;
    }
    return false;
}

void ComplexShape::draw()
{
    for (auto & s : vec)
    {
        s->draw();
    }
}

