#include "cadeau.h"


string Cadeau::getDesc() const{
  return _description;
}

bool Cadeau::memeCadeau(const string & cadeau) const{
    bool meme;
    meme = (cadeau == getDesc());
    return meme;
}
