// Shelf.h  -- declaration only
#ifndef SHELF_H
#define SHELF_H

#include "Rectangle.h"

class Shelf
{
    private:
        Rectangle size;          // has-a: a Shelf HAS a Rectangle
        double    costPerSqFt;

        bool isOversized() const;   // private: only member functions can call it

    public:
        Shelf();                                  // Default constructor
        bool   setDimensions(double length, double width);
        void   setCostPerSqFt(double price);
        double getArea() const;
        double getCost() const;
};
#endif
