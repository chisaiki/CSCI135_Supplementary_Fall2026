/*
(A)
    8 5 -4
    8 -9 4

*/

#include <iostream>

using namespace std;

// Note carefully which parameters have an &
void tweak(int &a, int b, int &c);

int main()
{
    int x = 3, y = 5, z = 7;

    tweak(x, y, z);
    cout << x << " " << y << " " << z << endl;

    tweak(z, x, y);   // Same function, different order!
    cout << x << " " << y << " " << z << endl;
    return 0;
}

void tweak(int &a, int b, int &c)
{
    a = a + b;
    b = b + c;
    c = a - b;
}