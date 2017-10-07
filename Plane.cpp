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
    delete [] this->firstClass;
    delete [] this->economy;
}

void Plane::initSeatArrays() {
    this->firstClass = new Seat*[this->firstClassRows];
    for (int row = 0; row < this->firstClassRows; row++) {
        this->firstClass[row] = new Seat[this->firstClassCols](); 
        for (int col = 0; col < this->firstClassCols; col++) {
            //this->firstClass[row][col] = new Seat(); 
        }
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
