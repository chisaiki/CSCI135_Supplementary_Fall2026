// Shelf.cpp  -- definitions (no cin / cout in here)
#include "Shelf.h"

Shelf::Shelf()
{
    size.setLength(0);
    size.setWidth(0);
    costPerSqFt = 0;
}

// Private helper: true when the area is over 50 sq ft
bool Shelf::isOversized() const
{
    return size.calcArea() > 50;
}

bool Shelf::setDimensions(double len, double wid)
{
    if (len < 0 || wid < 0)              // reject negatives
        return false;

    double oldLen = size.getLength();    // remember the old size
    double oldWid = size.getWidth();

    size.setLength(len);
    size.setWidth(wid);

    if (isOversized())                   // reject oversized shelves
    {
        size.setLength(oldLen);          // put the old size back
        size.setWidth(oldWid);
        return false;
    }
    return true;
}

void Shelf::setCostPerSqFt(double cost)
{
    if (cost >= 0)
        costPerSqFt = cost;
}

double Shelf::getArea() const
{
    return size.calcArea();
}

double Shelf::getCost() const
{
    return getArea() * costPerSqFt;
}
