#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "chocolate.h"
#include "chocolatebox.h"
using namespace std;

const int NBADD = 20;

ChocolateBox::ChocolateBox(string name, vector<Chocolate>){
    _name = name;
    fillBox();
}

void ChocolateBox::fillBox(){
    for (int i = 0; i < NBADD; i++) _content.push_back(Chocolate(20));
}

void ChocolateBox::display(ostream & o) const{
    o << "Name of the box: ";
    o << _name << endl;
    o << "Number of chocolates: ";
    o << _content.size() << endl;
    for (int i = 0; i < _content.size(); i++) o << "Color of the chocolate " << i <<" :" << _content[i].theType() << endl;
}

ostream & operator << (ostream & o, const ChocolateBox & cb){
    cb.display(o);
    return o;
}

void ChocolateBox::addChocolate(const Chocolate & c){
    _content.push_back(c);
    cout << "Chocolate added to the box" << endl;
}

bool ChocolateBox::eatChocolate(){
    bool eat = (_content.size() != 0);
    if (eat){
        string name = _content[_content.size()-1].theType();
        _content.pop_back();
        cout << name << " chocolate has been slain" << endl;
    }

    return eat;
}

string ChocolateBox::theName() const{
    return _name;
}

int ChocolateBox::theWeight() const{
    int w = 0;
    for (int i = 0; i < _content.size(); i++) w += _content[i].theWeight();
    return w;
}
