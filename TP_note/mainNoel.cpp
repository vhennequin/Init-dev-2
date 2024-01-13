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
  /// --------- Vous pouvez déclarer de nouvelles variables
  /// --------- appeler les méthodes écrites, et faire des affichages
  /// ------- ceci ne sera pas évalué



  /// --------------- insérer ici les instructions de la question 5
  /// Obligatoire : tests automatiques de la méthode *possede* de la classe Enfant)
    cout << "Test de la méthode possède, attendu faux" << endl;
    e.affiche();
    meme = e.possede(c);
    if (meme) cout << "Echec" << endl;
    else cout << "Succès" << endl;
    cout << "On reessaye avec cette fois ci un objet en doublon, attendu vrai" << endl;
    e.recoitCadeau(c); // on rappelle que c est par défaut l'objet orange
    meme = e.possede(c);
    e.affiche();
    if (meme) cout << "Succès, orange est bien présent 2 fois" << endl;
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
  /// Compléter les instructions ci-dessous pour la distribution des cadeaux
  int i=0;
  bool encoreDesCadeaux; // le pere Noel a-t-il encore des cadeaux dans sa hotte ?
    encoreDesCadeaux = p.offreCadeau(lesEnfants[0]);
  // écrire  l'instruction d'amorçage  :
  // - le pere Noël offre un cadeau au 1er enfant : lesEnfants[0]
  // - le booleen encoreDesCadeaux est initialisé.

  while (encoreDesCadeaux){  /// tant qu'il a des cadeaux
    i++;
    if(i==lesEnfants.size())i=0;// recommence au 1er enfant
    encoreDesCadeaux = p.offreCadeau(lesEnfants[i]);
  // écrire l'instruction de relance :
  // - le pere Noël offre un cadeau à l'enfant numéro i
  // - le booleen encoreDesCadeaux est mis à jour

  }

  /// --------------- Question 11 ----------
  /// trouver l'enfant qui a le plus de cadeaux et afficher ses cadeaux
  return 0;
}

