// Rectangle.cpp
#include "Rectangle.h"

bool Rectangle::setLength(double len)
{
    if (len < 0)
        return false;
    length = len;
    return true;
}

bool Rectangle::setWidth(double wid)
{
    if (wid < 0)
        return false;
    width = wid;
    return true;
}

double Rectangle::getLength() const { return length; }
double Rectangle::getWidth()  const { return width; }
double Rectangle::calcArea()  const { return length * width; }
