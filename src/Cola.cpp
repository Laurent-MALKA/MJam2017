#include "Cola.hpp"

Cola::Cola(Perso *monPerso, SDL_Texture* txt) : Bonus(monPerso, txt) {
    setY(0);
    setX(0);
    setW(50);
    setH(50);
}

void Cola::effet() {
    Bonus::utilise=true;
    setX(monPerso->getX());
    setY(monPerso->getY());
    directionX=(int)monPerso->getAcc_h();
    directionX=(directionX>=0)? 15 : -15;
    directionY=(int)monPerso->getV_v_act();
    directionY=(directionY>0)? 15 : -15;
}

void Cola::bouger() {
    setX(getX()+directionX);
    setY(getY()+directionY);
}

void Cola::mort(Perso* perso) {
    perso->setV_v_act(-perso->getV_v_act());
    Bonus::mort(perso);
}
