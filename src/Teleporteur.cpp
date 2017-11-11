#include "Teleporteur.hpp"

Teleporteur::Teleporteur(Perso *p) : Bonus(p) {

}

void Teleporteur::effet() {
    Bonus::utilise=true;
    setX(monPerso->getX());
    setY(monPerso->getY());
    setW(25);
    setH(25);
    directionX=(int)monPerso->getAcc_h();
    directionX=(directionX>=0)? 12 : -12;
    directionY=(int)monPerso->getV_v_act();
    directionY=(directionY>0)? 12 : -12;
}

void Teleporteur::bouger() {
    setX(getX()+directionX);
    setY(getY()+directionY);
}

void Teleporteur::mort(Perso* perso) {
    int tmpX, tmpY;
    tmpX=perso->getX();
    tmpY=perso->getY();
    perso->setX(monPerso->getX());
    perso->setY(monPerso->getY());
    monPerso->setX(tmpX);
    monPerso->setY(tmpY);

    Bonus::mort(perso);
}



// GrappinSpe::effet() {}
