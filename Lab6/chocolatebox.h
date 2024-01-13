#ifndef CHOCOLATEBOX_H_INCLUDED
#define CHOCOLATEBOX_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "chocolate.h"
using namespace std;

class ChocolateBox{
    string _name; // name of the box
    vector<Chocolate> _content;   //the Chocolates contained in the box
public:
    ChocolateBox(string = "classic", vector<Chocolate> = {Chocolate(20)});
    void fillBox();
    void display(ostream&o)const;
    void addChocolate(const Chocolate & );
    bool eatChocolate();
    string theName() const;
    int theWeight() const;
};

ostream & operator << (ostream &, const ChocolateBox &);

#endif // CHOCOLATEBOX_H_INCLUDED
