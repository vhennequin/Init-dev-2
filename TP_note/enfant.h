#ifndef _ENFANT_
#define _ENFANT_
#include <vector>

class Enfant {
   private:
    vector<string> _sac;
    string _nom;
 public:
    Enfant(const string & n="toto", const vector<string> & sac = {});
    string nom()const;

    void affiche() const;

    void recoitCadeau(const Cadeau &);

    bool possede(const Cadeau &);

};

#endif
