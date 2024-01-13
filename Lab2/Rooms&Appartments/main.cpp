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
    Room r1;
    try{
        r1 = Room(5, 2, "Yabicho's_grave");
        Room r3(-2, 4, "Bathroom");
    }
    catch (const invalid_argument & e){
        cerr << "Error: " << e.what() << endl;
    }

    test.display();
    r1.display();
    Room r2;

    try{
        r2.input();
    }
    catch (const invalid_argument & e){
        cerr << "Error: " << e.what() << endl;
    }

    r2.display();
    cout << "The room is "<< r2.area() << " square meters." << endl;
    cout << r1.area() << endl;
    bool larger;
    larger = r1.isLarger(r2);
    if (larger){
        cout << "The first room is larger than the second" << endl;
    }
    else{
        cout << "The second room is larger than the first" << endl;
    }

    cout << "Class Apartment" << endl;
    Apartment nothing;
    Apartment a1("4 rue de la Joie, 91190 Gif-sur-Yvette", {r1}, 0);
    a1.display();
    cout << "Adding a room to the apartment" << endl;
    a1.addRoom(r2);
    cout << "The new apartment: " << endl;
    a1.display();
    cout << "The apartment has " << a1.area() << " square meters" << endl;
    Apartment a2("5 rue Vauban 92000 Nanterre", {r1,r1,r2}, 0);
    cout << "Comparison of size for the two apartments: " << endl;
    int apartmentsize;
    apartmentsize = a1.compare(a2);
    if (apartmentsize == 1) cout << "The first apartment is bigger than the second" << endl;
    else {
        if (apartmentsize == 0) cout << "The two apartments are the same size" << endl;
        else cout << "The second apartment is bigger than the first" << endl;
    }
    cout << "Value of the first apartment: " << a1.value() <<endl;
    cout << "Value of the second apartment: " << a2.value() <<endl;
    int value;
    value = a1.comparePrice(a2);
    if (value == 1) cout << "The first apartment is more expensive than the second" << endl;
    else {
        if (value == 0) cout << "The two apartments have the same price" << endl;
        else cout << "The second apartment is more expensive than the first" << endl;
    }

    // part 4
    ofstream output;
    try {
        output.open("room.txt");
        r1.writeFile(output);
        output.close();
        output.open("Room2.txt");
        r2.writeFile(output);
        output.close();
    }
    catch (const string & s) {
        cerr<< "Problem encountered while opening file: " << s;
    }
    ifstream input;
    Room r3, r4;
       try {
        input.open("room.txt");
        r3 = (input);
        input.close();
        input.open("Room2.txt");
        r4 = (input);
        input.close();
    }
    catch (const string & s) {
        cerr<< "Problem encountered while opening file: " << s;
    }
    r3.display();
    r4.display();
    return 0;
}
