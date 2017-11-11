#include "Bonus.hpp"

Bonus::Bonus(Perso *monPerso) : monPerso(monPerso), utilise(false){

}


void Bonus::mort(Perso* p) {

    monPerso->setBonus(NULL);
}

Bonus::~Bonus() {
    delete monPerso;
}

bool Bonus::getUtilise() const {
    return utilise;
}
