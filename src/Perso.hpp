#ifndef MJAM2017_PERSO_HPP
#define MJAM2017_PERSO_HPP


#include "Touches.hpp"
#include "Bonus.hpp"
#include "Body.hpp"
#include "Grappin.hpp"

class Perso {

public:
    Perso(Body body, Touches touches);
    void deplacement();
    void saut();
private:
    float v_h_max;
    float v_h_act;
    float v_h_accG;
    float v_h_accD;
    float v_v_act;
    bool enLAir;
    unsigned nbBiere;
    Bonus *bonus;
    Touches touches;
    Body body;
    Grappin grappin;
};


#endif //MJAM2017_PERSO_HPP
