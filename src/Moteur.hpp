#ifndef MJAM2017_MOTEUR_HPP
#define MJAM2017_MOTEUR_HPP

#include "Inputs.hpp"

class Moteur {
public:
    Moteur();
    void deplacements();

private:
    Inputs inputs;
};


#endif //MJAM2017_MOTEUR_HPP
