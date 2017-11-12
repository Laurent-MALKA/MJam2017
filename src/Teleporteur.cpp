#include <iostream>
#include "Teleporteur.hpp"

Teleporteur::Teleporteur(Perso *p, SDL_Texture* txt) : Bonus(p, txt) {
    setY(0);
    setX(0);
    setW(25);
    setH(25);
}

void Teleporteur::effet() {
    Bonus::utilise=true;
    setX(monPerso->getX());
    setY(monPerso->getY());
    directionX=(int)monPerso->getAcc_h();
    directionX=(directionX>=0)? 12 : -12;
}

void Teleporteur::bouger() {
    setX(getX()+directionX);
    std::cout<<"x="<<getX()<<", y="<<getY()<<std::endl;
}

void Teleporteur::mort(Perso* perso) {
    int tmpX, tmpY;
    if(perso!= nullptr) {
        tmpX = perso->getX();
        tmpY = perso->getY();
        perso->setX(monPerso->getX());
        perso->setY(monPerso->getY());
        monPerso->setX(tmpX);
        monPerso->setY(tmpY);
    }
    Bonus::mort(perso);
}
