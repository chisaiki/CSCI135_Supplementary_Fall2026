// 7.16 Screen Control & 7.17 Yoyo Animation
// Part 1: uses cursor positioning to lay out a data-entry form.
// Part 2: uses the same cursor control to animate a yoyo going
//         down its string and back up.
//
// Compile:  g++ -std=c++11 yoyo.cpp -o yoyo
// Windows uses the Win32 console API (like the textbook);
// macOS/Linux use ANSI escape codes.

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


// ---------------- Screen control functions ----------------
void placeCursor(int row, int col)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = col;   // column
    position.Y = row;   // row
    SetConsoleCursorPosition(screen, position);
}

void clearScreen() { system("cls"); }

void pauseMs(int ms) { Sleep(ms); }

void showCursor(bool visible)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(screen, &info);
    info.bVisible = visible;
    SetConsoleCursorInfo(screen, &info);
}

// Print text at a specific row and column
void printAt(int row, int col, const string &text)
{
    placeCursor(row, col);
    cout << text << flush;
}

// ---------------- Part 1: Screen control demo ----------------
void screenControlDemo()
{
    string name, city;
    int age;

    clearScreen();
    printAt(2, 10, "******* Student Information Form *******");
    printAt(4, 10, "Name: ");
    printAt(6, 10, "Age:  ");
    printAt(8, 10, "City: ");

    // Move the cursor right after each prompt to read input
    placeCursor(4, 16);
    getline(cin, name);

    placeCursor(6, 16);
    cin >> age;
    cin.ignore(1000, '\n');

    placeCursor(8, 16);
    getline(cin, city);

    clearScreen();
    printAt(2, 10, "You entered:");
    printAt(4, 12, "Name: " + name);
    printAt(5, 12, "Age:  " + to_string(age));
    printAt(6, 12, "City: " + city);
    printAt(9, 10, "Press Enter to see the yoyo animation...");
    cin.get();
}

// ---------------- Part 2: Yoyo animation ----------------
class Yoyo
{
private:
    int col;        // column the string hangs from
    int topRow;     // row where the string starts (the hand)
    int length;     // how far down the yoyo travels
    int delay;      // milliseconds between frames

public:
    Yoyo(int c, int top, int len, int d)
        : col(c), topRow(top), length(len), delay(d) {}

    void drawHand() const
    {
        printAt(topRow - 1, col - 2, "\\_|_/");   // the hand
    }

    // Drop the yoyo down the string one row at a time
    void throwDown() const
    {
        for (int i = 1; i <= length; i++)
        {
            printAt(topRow + i - 1, col - 1, " | ");   // string replaces old yoyo
            printAt(topRow + i,     col - 1, "(O)");   // yoyo in new spot
            pauseMs(delay);
        }
    }

    // Wind the yoyo back up, erasing as it goes
    void pullUp() const
    {
        for (int i = length; i >= 1; i--)
        {
            printAt(topRow + i,     col - 1, "   ");   // erase yoyo
            printAt(topRow + i - 1, col - 1, "(O)");   // yoyo moves up
            pauseMs(delay);
        }
        printAt(topRow, col - 1, " | ");               // back in the hand
    }
};

void yoyoAnimation()
{
    const int THROWS = 3;
    Yoyo yoyo(30, 3, 12, 80);   // column 30, start row 3, 12 rows long, 80 ms

    clearScreen();
    showCursor(false);
    printAt(0, 20, "Yoyo Animation");
    yoyo.drawHand();
    printAt(3, 29, " | ");

    for (int t = 0; t < THROWS; t++)
    {
        yoyo.throwDown();
        pauseMs(200);        // brief "sleeper" at the bottom
        yoyo.pullUp();
        pauseMs(300);
    }

    showCursor(true);
    printAt(18, 0, "Done!\n");
}

int main()
{
    screenControlDemo();
    yoyoAnimation();
    return 0;
}
