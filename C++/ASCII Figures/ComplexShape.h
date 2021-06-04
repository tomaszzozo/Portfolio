#pragma once
#include "Shape.h"
#include <iostream>
#include <vector>

class ComplexShape : public Shape
{
    std::vector<Shape*> vec;
public:
    explicit ComplexShape(Display* w);
    bool add(Shape* o);
    void draw() final;
};
