#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include "apartment.h"
#include "room.h"
using namespace std;

Room::Room(){
    cout << "empty constructor" << endl;
    _width = 3;
    _length = 4;
    _name = "emptyroom";
}

Room::Room(float width, float length, string name){
    _width = width;
    _length = length;
    for (int i = 0; i < name.size(); i++) _name += tolower(name[i]);
    if (width < 0 || length < 0) throw(invalid_argument("A value can't be negative"));
    else{
        if (width > length){
        float temp = _width;
        _width = _length;
        _length = temp;
        }
    }
}

void Room::display() const{
    cout << "-" << "\t" << _name << " that is " << area() << " square meters" << endl;
}

void Room::input(){
    string name;
    float width, length;
    cout << "Please enter the width of the room: " << endl;
    cin >> width;
    if (width < 0) throw(invalid_argument("Not a positive width entered"));
    cout << "Please enter the length of the room: " << endl;
    cin >> length;
    if (length < 0) throw(invalid_argument("Not a positive length entered"));
    cout << "What is the name of the room? : " << endl;
    cin >> name;
    for (int i = 0; i < name.size(); i++) name[i] = tolower(name[i]);
    _width = width;
    _length = length;
    _name = name;
    if (_width > _length){
        float temp = _width;
        _width = _length;
        _length = temp;
    }
}

float Room::area() const{
    float area;
    area = (_width * _length);
    return area;
}

bool Room::isLarger(const Room & r) const{
    bool result;
    result = ((_width * _length) > r.area());
    return result;
}

float Room::getLength() const{
    return _length;
}

float Room::getWidth() const{
    return _width;
}

string Room::getName() const{
    return _name;
}

float area(const Room & r){
    float area;
    area = (r.getWidth() * r.getLength());
}

void Room::writeFile(ofstream & output) const{
    if(!(output.is_open())) throw("File is not opened");
    output << _name << endl;
    output << _width << endl;
    output << _length << endl;
}

Room::Room(ifstream & input){
    if(!(input.is_open())) throw("File is not opened");
    input >> _name;
    input >> _width;
    input >> _length;
}
