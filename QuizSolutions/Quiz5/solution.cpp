/*
(A)
    A10 B5 5 X5 10 X10

*/

#include <iostream>

using namespace std;

class Counter
{
    private:
        int count;

    public:
        Counter()          // Default constructor
        { count = 10;  cout << "A" << count << " "; }

        Counter(int c)     // Constructor, 1 parameter
        { count = c;   cout << "B" << count << " "; }

        void setCount(int c)
        { if (c >= 0) count = c; }

        int getCount()
        { return count; }

        ~Counter()         // Destructor
        { cout << "X" << count << " "; }
};

void demo()
{
    Counter c2(5);
    c2.setCount(-3);
    cout << c2.getCount() << " ";
}

int main()
{
    Counter c1;
    demo();
    cout << c1.getCount() << " ";
    return 0;
}
