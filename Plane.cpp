#include <iostream>
#include "Plane.h"
using namespace std;

Plane::Plane() {
    cout << "CREATING PLANE" << endl;
    cout << "Enter number of first class rows: ";
    cin >> this->firstClassRows;
    cout << "Enter number of first class columns: ";
    cin >> this->firstClassCols;

    cout << "Enter number of econ class rows: ";
    cin >> this->econRows;
    cout << "Enter number of econ class columns: ";
    cin >> this->econCols;
    this->initAllSeats();
}

Plane::Plane(int firstClassRows, int firstClassCols, int econRows, int econCols) {
    this->firstClassRows = firstClassRows;
    this->firstClassCols = firstClassCols;
    this->econRows = econRows;
    this->econCols = econCols;
    this->initAllSeats();
}

Plane::~Plane() {
    this->deleteAllSeats();
}

void Plane::initAllSeats() {
    this->firstClass = new Seat*[this->firstClassRows];
    for (int row = 0; row < this->firstClassRows; row++) {
        this->firstClass[row] = new Seat[this->firstClassCols](); 
    }
    this->economy = new Seat*[this->econRows];
    for (int row = 0; row < this->econCols; row++) {
        this->economy[row] = new Seat[this->econCols](); 
    }
}

void Plane::deleteAllSeats() {
    for (int row = 0; row < this->firstClassRows; row++) {
        delete [] this->firstClass[row]; 
    }
    for (int row = 0; row < this->econCols; row++) {
        delete [] this->economy[row]; 
    }
    delete [] this->firstClass;
    delete [] this->economy;
}

void Plane::displaySeats() {
    cout << "PLANE SEATING MAP" << endl;
    cout << "First Class" << endl;
    cout << "-----------" << endl;
    for (int row = 0; row < this->firstClassRows; row++) {
        for (int col = 0; col < this->firstClassCols; col++) {
            cout << this->firstClass[row][col].status << " ";
        }
        cout << endl;
    }
    cout << "Economy" << endl;
    cout << "-------" << endl;
    for (int row = 0; row < this->econRows; row++) {
        for (int col = 0; col < this->econCols; col++) {
            cout << this->economy[row][col].status << " ";
        }
        cout << endl;
    }
}

void Plane::bookSeat() {
    bool isFirstClass = false; 
    int row;
    int seatInRow;
    cout << "Enter 1 to book a first class seat or 0 to book an economy seat: ";
    cin >> isFirstClass;
    cout << "Enter row number of the seat you'd like to book: ";
    cin >> row;
    cout << "Enter seat number you'd like to book: ";
    cin >> seatInRow;

    if (this->isValidSeat(isFirstClass, row, seatInRow)) {
        Seat* seatToBook = this->getSeat(isFirstClass, row, seatInRow);
        if (!seatToBook->isBooked) {
            seatToBook->isBooked = true;
            seatToBook->status = 'x';
            cout << "Seat successfully booked" << endl;
        } else {
            cout << "This seat is already booked" << endl;
        }
    } else {
        cout << "Invalid seat selection" << endl;
    }
}

void Plane::checkSeat() {
    bool isFirstClass = false; 
    int row;
    int seatInRow;
    cout << "Enter 1 to check a first class seat or 0 to check an economy seat: ";
    cin >> isFirstClass;
    cout << "Enter row number of the seat you'd like to check: ";
    cin >> row;
    cout << "Enter seat number you'd like to check: ";
    cin >> seatInRow;

    if (this->isValidSeat(isFirstClass, row, seatInRow)) {
        Seat* seatToCheck = this->getSeat(isFirstClass, row, seatInRow);
        if (seatToCheck->isBooked) {
            cout << "Seat is booked" << endl;
        } else {
            cout << "Seat is not booked" << endl;
        }
    } else {
        cout << "Invalid Seat Selection" << endl;
    }
}

void Plane::clearSeat() {
    bool isFirstClass = false; 
    int row;
    int seatInRow;
    cout << "Enter 1 to clear a first class seat or 0 to clear an economy seat: ";
    cin >> isFirstClass;
    cout << "Enter row number of the seat you'd like to clear: ";
    cin >> row;
    cout << "Enter seat number you'd like to clear: ";
    cin >> seatInRow;

    if (this->isValidSeat(isFirstClass, row, seatInRow)) {
        Seat* seatToClear = this->getSeat(isFirstClass, row, seatInRow);
        if (seatToClear->isBooked) {
            seatToClear->isBooked = false;
            seatToClear->status = '-';
            cout << "Seat is cleared" << endl;
        } else {
            cout << "Seat was not cleared. Seat was not booked" << endl;
        }
    } else {
        cout << "Invalid Seat Selection" << endl;
    }
}

void Plane::clearAllSeats() {
    this->deleteAllSeats();
    this->initAllSeats();
    cout << "All seats cleared" << endl;
}

Seat* Plane::getSeat(bool isFirstClass, int rowNum, int seatNum) {
    if (isFirstClass) {
        return &(this->firstClass[rowNum][seatNum]);
    } else {
        return &(this->economy[rowNum][seatNum]);
    }
}

bool Plane::isValidSeat(bool isFirstClass, int rowNum, int seatNum) {
    if (isFirstClass) {
        return this->firstClassRows >= rowNum && this->firstClassCols >= seatNum;
    } else {
        return this->econRows >= rowNum && this->econCols >= seatNum;
    }
}

