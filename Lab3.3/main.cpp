#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "apartment.h"
#include "room.h"
using namespace std;

int main()
{
    Room test;
    Apartment r1;
    r1.addRoom(Room(4,4,"room01"));
    r1.addRoom(Room(4,4,"room02"));
    r1.addRoom(Room(4,4,"room03"));
    r1.addRoom(Room(4,4,"room04"));
    r1.addRoom(Room(4,4,"room05"));
    r1.addRoom(Room(4,4,"room06"));
    r1.addRoom(Room(4,4,"room07"));
    r1.addRoom(Room(4,4,"room08"));
    r1.addRoom(Room(4,4,"room09"));
    r1.addRoom(Room(4,4,"room10"));
    test.display();
    r1.display();
    int index;
    index = r1.searchRoom("room08");
    cout << "index of the searched room is " << index << endl;

    Apartment r2;
    r2.addRoom(Room(4,4,"room02"));
    r2.addRoom(Room(4,4,"room04"));
    r2.addRoom(Room(4,4,"room04"));
    r2.addRoom(Room(4,4,"room04"));
    r2.addRoom(Room(4,4,"room04"));
    r2.addRoom(Room(4,4,"room06"));
    r2.addRoom(Room(4,4,"room10"));
    r2.addRoom(Room(4,4,"room10"));
    r2.addRoom(Room(4,4,"room10"));
    r2.addRoom(Room(4,4,"room10"));
    index = r2.searchFirst("room04");
    cout << "index of the searched room is " << index << endl;
    return 0;
}
