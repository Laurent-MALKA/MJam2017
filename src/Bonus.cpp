#include "Bonus.hpp"

Bonus::Bonus(Perso *monPerso, SDL_Texture* txt) : monPerso(monPerso), utilise(false), txt(txt), ramasse(false){
}


void Bonus::mort(Perso* monPerso) {

    monPerso->setBonus(nullptr);
}

Bonus::~Bonus() = default;

bool Bonus::isUtilise() const {
    return utilise;
}

void Bonus::display(SDL_Renderer *rdr) {
    SDL_Rect r;
    r.x=getX();
    r.y=getY();
    r.w=getW();
    r.h=getH();

}

bool Bonus::isRamasse() const {
    return ramasse;
}

void Bonus::setRamasse(bool ram) {
    ramasse=ram;
}
