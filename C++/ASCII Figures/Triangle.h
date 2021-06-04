#pragma once
#include "Shape.h"

class Triangle : public Shape
{
    int a1, a2, b1, b2;
public:
    Triangle(Display* w, int a1, int a2, int b1, int b2);
    void draw() final;
};
