#ifndef PLANE_H
#define PLANE_H

struct Seat {
    char status = '-';
    bool isBooked = false;
};

class Plane {
    Seat** firstClass;
    Seat** economy;
    int firstClassRows;
    int firstClassCols;
    int econRows;
    int econCols;

    public:
        Plane();
        Plane(int firstClassRows, int firstClassCols, int econRows, int econCols);
        void displaySeats();
        void bookSeat();
        void checkSeat();
        void clearSeat();
        void clearAllSeats();
        ~Plane();
    private:
        void initSeatArrays();
        void setSeatToBooked(Seat* seatToBook);
};

#endif
