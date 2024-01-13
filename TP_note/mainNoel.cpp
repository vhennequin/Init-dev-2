#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"
#include <iostream>
#include <vector>
using namespace std;


int main(){
  vector<Enfant>lesEnfants; // les enfants qui attendent leurs cadeaux
  cout << "o o o Bonjour les enfants o o o " << endl;
  Cadeau c;
  bool meme;
  meme = c.memeCadeau("orange");
  cout << meme << endl;
  Enfant e ("Tata", {"style", "bruh"});
  e.affiche();
  Enfant e1;
    e1.affiche();
    e.recoitCadeau(c);
    PereNoel p;
  /// --------- Vous pouvez d�clarer de nouvelles variables
  /// --------- appeler les m�thodes �crites, et faire des affichages
  /// ------- ceci ne sera pas �valu�



  /// --------------- ins�rer ici les instructions de la question 5
  /// Obligatoire : tests automatiques de la m�thode *possede* de la classe Enfant)
    cout << "Test de la m�thode poss�de, attendu faux" << endl;
    e.affiche();
    meme = e.possede(c);
    if (meme) cout << "Echec" << endl;
    else cout << "Succ�s" << endl;
    cout << "On reessaye avec cette fois ci un objet en doublon, attendu vrai" << endl;
    e.recoitCadeau(c); // on rappelle que c est par d�faut l'objet orange
    meme = e.possede(c);
    e.affiche();
    if (meme) cout << "Succ�s, orange est bien pr�sent 2 fois" << endl;
    else cout << "Echec" << endl;

  ///---------------  Question 9 : ajouter 4 enfants au vector lesEnfants
    Enfant ea ("Asterix");
    Enfant eb ("Boul");
    Enfant ec ("Bill");
    Enfant ed ("Kirikou");
    lesEnfants.push_back(ea);
    lesEnfants.push_back(eb);
    lesEnfants.push_back(ec);
    lesEnfants.push_back(ed);

  /// --------------- Question  10
  /// Compl�ter les instructions ci-dessous pour la distribution des cadeaux
  int i=0;
  bool encoreDesCadeaux; // le pere Noel a-t-il encore des cadeaux dans sa hotte ?
    encoreDesCadeaux = p.offreCadeau(lesEnfants[0]);
  // �crire  l'instruction d'amor�age  :
  // - le pere No�l offre un cadeau au 1er enfant : lesEnfants[0]
  // - le booleen encoreDesCadeaux est initialis�.

  while (encoreDesCadeaux){  /// tant qu'il a des cadeaux
    i++;
    if(i==lesEnfants.size())i=0;// recommence au 1er enfant
    encoreDesCadeaux = p.offreCadeau(lesEnfants[i]);
  // �crire l'instruction de relance :
  // - le pere No�l offre un cadeau � l'enfant num�ro i
  // - le booleen encoreDesCadeaux est mis � jour

  }

  /// --------------- Question 11 ----------
  /// trouver l'enfant qui a le plus de cadeaux et afficher ses cadeaux
  return 0;
}

