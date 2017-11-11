#ifndef MJAM2017_COLA_HPP
#define MJAM2017_COLA_HPP


#include "Bonus.hpp"

class Cola : public Bonus{

public:
    explicit Cola(Perso *monPerso);
    void effet() override;
    void mort(Perso* perso) override;
    void bouger() override;

private:
    int vitesse;
    int directionX;
    int directionY;
};


#endif //MJAM2017_COLA_HPP
