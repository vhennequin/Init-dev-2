#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"

PereNoel::PereNoel(){
    for (int i = 0; i < JEUX.size(); i++){
        _hotte.push_back(JEUX[i]);
    }
}

bool PereNoel::offreCadeau(Enfant & enfant){
    bool nonvide, ajout;
    nonvide = !(_hotte.size() == 0);
    if (nonvide){
        ajout = Enfant().possede(_hotte[_hotte.size()-1]);
        if (!ajout) {
            Cadeau gift;
            gift = _hotte.back();
            _hotte.pop_back();
            Enfant().recoitCadeau(gift);
            nonvide = !(_hotte.size() == 0);
        }
    }
    return nonvide;
}
