// client.cpp  -- main; all I/O lives here
#include <iostream>
#include <iomanip>
#include "Shelf.h"

using namespace std;

// Ordinary functions, NOT members of Shelf
Shelf makeShelf(double len, double wid, double cost)
{
    Shelf s;                    // local Shelf
    s.setDimensions(len, wid);
    s.setCostPerSqFt(cost);
    return s;                   // returned by value (a copy)
}

void displayShelf(const Shelf &s)
{
    cout << "Shelf area: " << s.getArea() << " sq ft" << endl;
    cout << fixed << setprecision(2);
    cout << "Total cost: $" << s.getCost() << endl;
}

int main()
{
    Shelf shelf = makeShelf(8, 4, 3.50);
    displayShelf(shelf);

    cout << endl;

    if (!shelf.setDimensions(10, 6))      // 60 sq ft > 50
    {
        cout << "Dimensions rejected:" << endl;
        cout << "shelf is oversized." << endl;
    }

    // shelf.isOversized();   // ERROR: isOversized is private

    return 0;
}
