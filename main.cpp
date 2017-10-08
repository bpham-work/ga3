#include <iostream>
#include "Plane.h"
using namespace std;

int main() {
    Plane COSC1430;
    int selection = -1;
    while (selection != 6) {
        cout << endl;
        cout << "Pick one of these options" << endl;
        cout << "1. Display all seats" << endl;
        cout << "2. Check a seat" << endl;
        cout << "3. Clear a seat" << endl;
        cout << "4. Book a seat" << endl;
        cout << "5. Empty all seats" << endl;
        cout << "6. Exit" << endl;
        cout << "Input: ";
        cin >> selection;
        cout << endl;
        switch (selection) {
            case 1:
                COSC1430.displaySeats();
                break;
            case 2:
                COSC1430.checkSeat();
                break;
            case 3:
                COSC1430.clearSeat();
                break;
            case 4:
                COSC1430.bookSeat();
                break;
            case 5:
                COSC1430.clearAllSeats();
                break;
            case 6:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid menu selection" << endl;
                break;
        }
    }
    return 0;
}
