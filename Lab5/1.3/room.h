#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room{
    float _width, _length;
    string _name;

public:

    Room();

    Room(float, float, string);

    void display() const;

    void input();

    float area() const;

    bool isLarger(const Room & ) const;

    float getLength() const;

    float getWidth() const;

    string getName() const;

    void writeFile(ofstream &) const;

    Room(ifstream &);

};

float area(const Room &);
#endif // ROOM_H_INCLUDED
