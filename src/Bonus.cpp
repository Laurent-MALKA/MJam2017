#include "Bonus.hpp"

Bonus::Bonus(Perso *monPerso) : monPerso(monPerso), utilise(false){

}


void Bonus::mort(Perso* monPerso) {

    monPerso->setBonus(nullptr);
}

Bonus::~Bonus() = default;

bool Bonus::getUtilise() const {
    return utilise;
}

void Bonus::display(SDL_Renderer *rdr) {
    SDL_Rect r;
    r.x=getX();
    r.y=getY();
    r.w=getW();
    r.h=getH();

}
