#include <iostream>
#include <string>
#include <random>
#include "chocolate.h"
using namespace std;

Chocolate::Chocolate(){
    _type = 0;
    _weight = 30;
}

Chocolate::Chocolate(string type, int weight){
    _type = _stringToType(type);
    _weight = weight;
}

Chocolate::Chocolate(int weight){
    _type = rand() % 3;
    _weight = weight;
}

string Chocolate::_typeToString(int n)const {  // returns the string equivalent to the type
 if (n!=0 && n!=1 && n!=2) throw string ("incorrect type");
 string s;
 switch(n){
   case 0: s="black";break;
   case 1: s="white";break;
   case 2: s="milk";break;
 }
 return s;
}

int Chocolate::_stringToType(string n)const{ // returns the type equivalent to the string
  if (n != BLACK && n != WHITE && n != MILK) throw string ("incorrect type");
  int type;
  if (n==BLACK) type = CBLACK;
  else if (n==WHITE) type = CWHITE;
  else type = CMILK;
  return type;
}

int Chocolate::theWeight() const{
    return _weight;
}

string Chocolate::theType() const{
    return _typeToString(_type);
}

ostream & operator << (ostream & o, const Chocolate & c){
    o  << "Type: " << c.theType() << " Weight: " << c.theWeight() << endl;
    return o;
}

bool Chocolate::operator < (const Chocolate & c) const{
    bool res = (_weight < c._weight);
    return res;
}
