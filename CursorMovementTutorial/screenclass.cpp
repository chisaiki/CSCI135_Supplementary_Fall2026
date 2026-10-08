#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

/* ---------- Class declaration (the "specification") ---------- */
class Screen
{
private:
    HANDLE handle;   // the console; hidden from the rest of the program

public:
    Screen();                                   // constructor
    bool placeCursor(int row, int col);         // move the cursor
    void printAt(int row, int col, const string &text);
    int rows() const;                           // visible rows
    int cols() const;                           // visible columns
};

/* ---------- Member function definitions (the "implementation") ---------- */

// Get the console handle once, when the Screen object is created
Screen::Screen()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

// Move the cursor; returns false (and prints why) if the move fails
bool Screen::placeCursor(int row, int col)
{
    cout << flush;               // make sure earlier text is on screen first

    COORD position;
    position.X = col;            // column
    position.Y = row;            // row

    if (!SetConsoleCursorPosition(handle, position))
    {
        cerr << "Cursor move to row " << row << ", col " << col
             << " failed, error " << GetLastError() << endl;
        return false;
    }
    return true;
}

// Move the cursor and print in one step
void Screen::printAt(int row, int col, const string &text)
{
    placeCursor(row, col);
    cout << text << flush;
}


/* ---------- Program ---------- */
int main()
{
    Screen screen;   // constructor gets the handle for us

    screen.printAt(5, 16, "Hello!");
    screen.printAt(10, 16, "Goodbye!");

    // Move the cursor below our text so the "press any key" prompt
    // or command prompt doesn't print on top of it
    screen.placeCursor(12, 0);

    return 0;
}