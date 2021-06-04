#pragma once
#include "Display.h"

class Shape
{
protected:
    Display* display;
public:
    explicit Shape(Display* w);
    virtual void draw(){};
    void changeDisplay(Display* newDisplay);
};
