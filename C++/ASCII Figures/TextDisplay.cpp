#include "TextDisplay.h"
#include <iostream>
#include "MyExcpetions.h"

using namespace std;

void TextDisplay::drawTriangle(int a1, int a2, int b1, int b2)
{
    int c1 = 0, c2 = 0;
    if ((a1 == b1 && a2 == b2) || (a1 == c1 && a2 == c2) || (b1 == c1 && b2 == c2))
    {
        throw MyExcpetions();
    }
    cout << "Drawing a triangle from vectors (" << a1 << ", " << a2 << ") (" << b1 << ", " << b2 << ")" << endl;
}

void TextDisplay::drawCircle(int r)
{
    if (r < 0)
    {
        throw MyExcpetions();
    }
    cout << "Drawing a circle with radius " << r << endl;
}

void TextDisplay::drawParallelogram(int a1, int a2, int b1, int b2)
{
    int c1 = 0, c2 = 0;
    if ((a1 == b1 && a2 == b2) || (a1 == c1 && a2 == c2) || (b1 == c1 && b2 == c2))
    {
        throw MyExcpetions();
    }
    cout << "Drawing a parallelogram from vectors (" << a1 << ", " << a2 << ") (" << b1 << ", " << b2 << ")" << endl;
}