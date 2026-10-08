#include <iostream>
using namespace std;

int main(){

    double furniture, painting, displayBoard;

    cout << "Enter the cost of the furniture: ";
    cin >> furniture;

    cout << "Enter the cost of painting the shop: ";
    cin >> painting;

    cout << "Enter the cost of the display board: ";
    cin >> displayBoard;

    double total = furniture + painting + displayBoard;

    cout << "Total amount spent on renovation: $" << total << endl;

    return 0;
}
