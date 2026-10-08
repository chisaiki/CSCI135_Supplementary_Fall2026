
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(){

    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    
    /*Set cursor location*/
    position.X = 16;   // column
    position.Y = 5;   // row

    /*Actually pass the values to the OS to put the cursor there*/
    if (!SetConsoleCursorPosition(screen, position))
    cout << "Cursor move failed, error " << GetLastError() << endl;
    
    cout << "Hello!" << endl;

    /*Set new location*/
    position.X = 16;   // column
    position.Y = 10;   // row

    /*Pass the data*/
    SetConsoleCursorPosition(screen, position);
    cout << "Goodbye!" << endl;



    /*Get the size of the screen*/
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(screen, &info);
    cout << "Buffer: " << info.dwSize.X << " cols x " << info.dwSize.Y << " rows" << endl;

}