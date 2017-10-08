#include <iostream>
#include "Plane.h"
using namespace std;

Plane::Plane() {
    cout << "Enter number of first class rows: ";
    cin >> this->firstClassRows;
    cout << "Enter number of first class columns: ";
    cin >> this->firstClassCols;

    cout << "Enter number of econ class rows: ";
    cin >> this->econRows;
    cout << "Enter number of econ class columns: ";
    cin >> this->econCols;
    this->initSeatArrays();
}

Plane::Plane(int firstClassRows, int firstClassCols, int econRows, int econCols) {
    this->firstClassRows = firstClassRows;
    this->firstClassCols = firstClassCols;
    this->econRows = econRows;
    this->econCols = econCols;
    this->initSeatArrays();
}

Plane::~Plane() {
    for (int row = 0; row < this->firstClassRows; row++) {
        delete [] this->firstClass[row]; 
    }
    for (int row = 0; row < this->econCols; row++) {
        delete [] this->economy[row]; 
    }
    delete [] this->firstClass;
    delete [] this->economy;
}

void Plane::initSeatArrays() {
    this->firstClass = new Seat*[this->firstClassRows];
    for (int row = 0; row < this->firstClassRows; row++) {
        this->firstClass[row] = new Seat[this->firstClassCols](); 
    }
    this->economy = new Seat*[this->econRows];
    for (int row = 0; row < this->econCols; row++) {
        this->economy[row] = new Seat[this->econCols](); 
    }
}

void Plane::displaySeats() {
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

    if (isFirstClass) {
        Seat* seatToBook = &(this->firstClass[row][seatInRow]);
        this->setSeatToBooked(&(*seatToBook));
    } else {
        Seat* seatToBook = &(this->economy[row][seatInRow]);
        this->setSeatToBooked(&(*seatToBook));
    }
}

void Plane::setSeatToBooked(Seat* seatToBook) {
    if (!seatToBook->isBooked) {
        seatToBook->isBooked = true;
        seatToBook->status = 'x';
        cout << "Seat booked" << endl;
    } else {
        cout << "This seat is already booked" << endl;
    }
}
