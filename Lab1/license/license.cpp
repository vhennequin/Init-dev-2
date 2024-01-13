// HB/CB november 2022 - version for students
// License class, to handle drivers licenses
// license.cpp file
#include <string>
#include <iostream>
#include <stdexcept>
#include "license.h"

using namespace std;


// constructeur vide
/*
License::License()
{
    cout << "Construction of a license" << endl;
    _name = "unknown";
    _firstName = "unknown";
    _date = "unknown";
    _number = "00000";
    _nbpoints = MAXP;
}
*/

// constructor
License::License(string name, string firstName, string date, string number, int points)
{
    cout << "Construction of a license" << endl;
    _name = name;
    _firstName = firstName;
    _date = date;
    _number = number;
    _nbpoints = points;
    if (_nbpoints < MINP) throw(invalid_argument("The number of points given is below the minimum"));
    else if (_nbpoints > MAXP) throw(invalid_argument("The number of points given is above the maximum"));
}

// display of a license
void License::display() const
{
    cout << "Information concerning the license of " << _firstName << " "<< _name << " :" << endl;
    cout << _number << endl;
    cout << _date << endl;
    cout << "Number of points : "<< _nbpoints << endl;
}

// number of points
int License::getNbpoints() const
{
    return _nbpoints;
}

// withdrawal of points
void License::withdrawPoints(int nbPointsWithdrawn)
{
    if (_nbpoints < MINP + nbPointsWithdrawn)
    {
        _nbpoints = MINP;
    }
    else
    {
        _nbpoints -= nbPointsWithdrawn;
    }
}

string License::getName() const{
    return _name;
}

void License::incrementPoints(){
    if (_nbpoints == MAXP) throw(invalid_argument("Already at max points."));
    else _nbpoints ++;
}

void License::decrementPoints(){
    if (_nbpoints == MINP) throw(invalid_argument("Already at min points."));
    else _nbpoints --;
}

void addPoints(License & l, int nbpoints){
    if (l.getNbpoints() + nbpoints <= MAXP){
        for (int i = 0; i < nbpoints; i++){
        l.incrementPoints();
        }
    }
    else{
        for (int i = l.getNbpoints(); i < MAXP; i++){
        l.incrementPoints();
        }
    }
}

License::~License() {
    License::display();
    cout << "Destruction of the license" << endl;
}

bool License::compare(const License & l1) const{
    bool result;
    result = (_nbpoints == l1.getNbpoints());
    return result;
}

void License::input(){
    License l;
    string surname, name, date, id;
    int points;
    cout << "Please enter a surname: " << endl;
    cin >> surname;
    _name = surname;
    cout << "Please enter a name: " << endl;
    cin >> name;
    _firstName = name;
    cout << "Please enter a date of birth: " << endl;
    cin >> date;
    _date = date;
    cout << "Please choose your id: " << endl;
    cin >> id;
    _number = id;
    cout << "How many points in your license? (0 to 12): " << endl;
    cin >> points;
    _nbpoints = points;

}
