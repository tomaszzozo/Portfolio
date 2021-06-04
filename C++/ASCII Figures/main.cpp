#include "GraphicalDisplay.h"
#include "TextDisplay.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"
#include "ComplexShape.h"
#include "Display.h"
#include "Shape.h"

using namespace std;

int main()
{
    Display *w1 = new GraphicalDisplay();
    Display *w2 = new TextDisplay();
    Shape* o1 = new Triangle(w1, 3, 2, 2,-2);
    Shape* o2 = new Parallelogram(w1, 3, 2, 2,-2);
    Shape* o3 = new Circle(w1, 5);
    auto* o4 = new ComplexShape(w1);
    o4->add(o1);
    o4->add(o2);
    o4->add(o3);
    o4->draw();
    o1->draw();
    o2->draw();
    o3->draw();
    o1->changeDisplay(w2);
    o2->changeDisplay(w2);
    o3->changeDisplay(w2);
    o4->changeDisplay(w2);
    o4->draw();
    o1->draw();
    o2->draw();
    o3->draw();
    delete o1;
    delete o2;
    delete o3;
    delete o4;
    return 0;
}

