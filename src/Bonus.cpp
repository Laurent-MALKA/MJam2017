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
