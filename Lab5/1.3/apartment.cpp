#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include "apartment.h"
#include "room.h"
using namespace std;

Apartment::Apartment(){
    cout << "empty constructor" << endl;
    _address = "1 rue Joliot-Curie 91400 Orsay";
    _zone = 0;
}

Apartment::Apartment(string address, vector<Room> rooms, int i){
    _address = address;
    _rooms = rooms;
    _zone = i;
}

void Apartment::display() const{
    cout << "The apartment is located at: " << _address << endl;
    cout << "it has " << nbRoom() << " rooms: " << endl;
    for (int i = 0; i < nbRoom(); i++){
        _rooms[i].display();
    }
    cout << "The zone is " << _zone << " with a price of " << ZONE[_zone] << " euros per square meter" << endl;
}

void Apartment::addRoom(const Room & newroom){
    _rooms.push_back(newroom);
    cout << "Successfully added to the apartment" << endl;
}

int Apartment::nbRoom() const{
    return _rooms.size();
}

float Apartment::area() const{
    float totalarea = 0;
    for (int i = 0; i < nbRoom(); i++){
        totalarea += _rooms[i].area();
    }
    return totalarea;
}

int Apartment::compare(const Apartment & app) const{
    int comparison;
    if (area() > app.area()) comparison = 1;
    else{
        if (area() == app.area()) comparison = 0;
        else comparison = -1;
    }
    return comparison;
}

float Apartment::value() const{
    return (ZONE[_zone] * area());
}

int Apartment::comparePrice(const Apartment & app) const{
    int comparison;
    if (value() > app.value()) comparison = 1;
    else{
        if (value() == app.value()) comparison = 0;
        else comparison = -1;
    }
    return comparison;
}

int Apartment::searchRoom(const string & name) const{
    int start, finish, middle;
    start = 0;
    finish = _rooms.size()-1;
    int ind = -1;
    while (ind == -1 && start <= finish){
        middle = (start + finish)/2;
        if (_rooms[middle].getName() == name) ind = middle;
        else{
            if (_rooms[middle].getName() > name) finish = middle-1;
            else start = middle+1;
        }
    }
    return (ind);
}

int Apartment::searchFirst(const string & name) const{
    int start, finish, middle;
    start = 0;
    finish = _rooms.size()-1;
    int ind = -1;
    while (ind == -1 && start <= finish){
        middle = (start + finish)/2;
        if (_rooms[middle].getName() == name){
            if (_rooms[middle-1].getName() == name){
                finish = middle-1;
            }
            else ind = middle;
        }
        else{
            if (_rooms[middle].getName() > name) finish = middle-1;
            else start = middle+1;
        }
    }
    return (ind);
}
///Marche pas
/*
void Apartment::writeFile(ofstream & output) const{
    output << _address << endl;
    output << _zone << endl;
    output << nbRoom() << endl;
    for (int i = 0; i < nbRoom(); i++){
        writeFile(output);
    }
}

Apartment::Apartment(ifstream & input){
    input >> _address;
    input >> _zone;
    input >> _rooms;
    for (int i = 0; i < nbRoom(); i++){
        input >> _rooms[i].display();
    }
}
*/

void Apartment::insertionSort(){
    int numPlace;
    Room current;
    for(int i = 1; i < _rooms.size(); i++){
        current = _rooms[i];
        numPlace = i;
        while (numPlace > 0 && _rooms[numPlace - 1].area() > current.area()){
            _rooms[numPlace] = _rooms[numPlace - 1];
            numPlace --;
        }
        _rooms[numPlace] = current;
    }
}
