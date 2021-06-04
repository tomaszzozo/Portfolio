#pragma once
#include "Shape.h"
#include <iostream>

class Circle : public Shape
{
    int r;
public:
    Circle(Display* w, int r);
    void draw() final;
};
