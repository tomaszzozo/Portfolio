#pragma once
#include "Display.h"

class TextDisplay : public Display
{
public:
    void drawTriangle(int a1, int a2, int b1, int b2) final;
    void drawCircle(int r) final;
    void drawParallelogram(int a1, int a2,int b1,int b2) final;
};
