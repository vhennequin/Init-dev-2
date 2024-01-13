#include <iostream>
#include <string>
#include <vector>
#include "room.h"
using namespace std;
#ifndef APPARTMENT_H_INCLUDED
#define APPARTMENT_H_INCLUDED

const vector<int> ZONE = {2500, 3100, 3500, 4150, 4500};

class Apartment{
    string _address;
    vector<Room> _rooms;
    int _zone;

public:
    Apartment();

    Apartment(string, vector<Room>, int);

    void display() const;

    void addRoom(const Room &);

    int nbRoom() const;

    float area() const;

    int compare(const Apartment &) const;

    float value() const;

    int comparePrice(const Apartment &) const;

    void writeFile(ofstream &) const;

    Apartment(ifstream &);
};

#endif // APPARTMENT_H_INCLUDED
