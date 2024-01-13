#ifndef _CADEAU_
#define _CADEAU_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cadeau {
  private:
    string _description;
  public:
    Cadeau(const string &desc="orange"){// cree un cadeau avec la description donnee, par d�faut le cadeau est une orange
      _description=desc;
    }
    string getDesc()const;    // retourne la description

    bool memeCadeau(const string &) const;

};

#endif





