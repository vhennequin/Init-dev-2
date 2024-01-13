#ifndef CHOCOLATE_H_INCLUDED
#define CHOCOLATE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

const float WEIGHT=30; // default weight (in grams)
const string BLACK= "black";
const int CBLACK = 0;
const string WHITE = "white";
const int CWHITE = 1;
const string MILK= "lait";
const int CMILK = 2;

class Chocolate{
    int _type; // 0 dark, 1 white, 2 milk
    int _weight; // weight of the chocolate
    string _typeToString(int n)const; // returns the string equivalent to the type
    int _stringToType(string)const; // returns the type equivalent to the string

public:
    Chocolate();
    Chocolate(string, int = WEIGHT);
    Chocolate(int);
    int theWeight() const;
    string theType() const;
    bool operator < (const Chocolate &) const;

};

ostream & operator << (ostream &, const Chocolate &);

#endif // CHOCOLATE_H_INCLUDED
