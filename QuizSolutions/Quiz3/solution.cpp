/*

Output: 

call 1: total is 110
call 2: total is 120
report sees 120
main total is 1


*/

#include <iostream>

using namespace std;

const int STEP = 5;          // Global constant
int total = 100;             // Global variable

void tally(int amount = STEP, int times = 2);
void report();

int main()
{
    int total = 1;           // Local: shadows the global
    tally();
    tally(10, 1);
    report();
    cout << "main total is " << total << endl;
    return 0;
}

void tally(int amount, int times)
{
    static int calls = 0;
    calls++;
    total += amount * times;
    cout << "call " << calls << ": total is " << total << endl;
}

void report()
{
    cout << "report sees " << total << endl;
}

