#include "Cola.hpp"

Cola::Cola(Perso *monPerso) : Bonus(monPerso) {}

void Cola::effet() {
    Bonus::utilise=true;
    setX(monPerso->getX());
    setY(monPerso->getY());
    setW(50);
    setH(50);
    directionX=(int)monPerso->getAcc_h();
    directionX=(directionX>=0)? 5 : -5;
    directionY=(int)monPerso->getV_v_act();
    directionY=(directionY>0)? 5 : -5;
}

void Cola::bouger() {
    setX(getX()+directionX);
    setY(getY()+directionY);
}

void Cola::mort(Perso* perso) {
    perso->setV_v_act(-perso->getV_v_act());
    Bonus::mort(perso);
}
