#ifndef MJAM2017_GRAPPINSPE_HPP
#define MJAM2017_GRAPPINSPE_HPP

#include "Perso.hpp"

class Teleporteur: public Bonus {
public:
    Teleporteur(Perso * p);

    void effet() override;
    void mort(Perso* perso) override;
    void bouger() override;

private:
    int vitesse;
    int directionX;
    int directionY;
};


#endif //MJAM2017_GRAPPINSPE_HPP
