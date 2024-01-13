#include "cadeau.h"
#include "enfant.h"
#include <vector>

Enfant::Enfant(const string &n, const vector<string> & sac){
  _nom=n;
  _sac = sac;
}
string Enfant::nom()const{
  return _nom;
}

void Enfant::affiche() const{
    cout << nom() << endl;
    for (int i = 0; i < _sac.size(); i++){
        cout << _sac[i] << endl;
    }
    if (_sac.size() == 0) cout << nom() << " n'a pas encore de cadeaux." << endl;
}

void Enfant::recoitCadeau(const Cadeau & cadeau){
    _sac.push_back(Cadeau().getDesc());
}

bool Enfant::possede(const Cadeau & cadeau){
    int doublon = 0;
    int i = 0;
    bool result = false;
    while (i < _sac.size() && !result){
        if (_sac[i] == Cadeau().getDesc()) doublon++;
        i++;
        result = (doublon >= 2);
    }
    return result;
}
