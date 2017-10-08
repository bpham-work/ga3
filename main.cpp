#include <iostream>
#include "Plane.h"
using namespace std;

int main() {
    Plane plane;
    int selection = -1;
    while (selection != 6) {
        cout << "Pick one of these options" << endl;
        cout << "1. Display all seats" << endl;
        cout << "2. Check a seat" << endl;
        cout << "3. Clear a seat" << endl;
        cout << "4. Book a seat" << endl;
        cout << "5. Empty all seats" << endl;
        cout << "6. Exit" << endl;
        cout << "Input: ";
        cin >> selection;
        switch (selection) {
            case 1:
                plane.displaySeats();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                plane.bookSeat();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
    return 0;
}
