#ifndef MJAM2017_PERSO_HPP
#define MJAM2017_PERSO_HPP


#include <SDL2/SDL_system.h>
#include <vector>
#include "Touches.hpp"
#include "Bonus.hpp"
#include "Body.hpp"
#include "Grappin.hpp"
#include "Animation.hpp"

class Perso {

public:
    Perso(Body body, Touches touches);

    const Touches &getTouches() const;

    void setAcc_h(float acc_h);

    void setV_v_act(float v_v_act);

    void setEnLAir(bool enLAir);

    bool isEnLAir() const;

    bool isGoingLeft() const;

    void deplacement();
    void saut();

private:
    /*
    SDL_Texture *texture;
    Animation *animation;
    std::vector<Animation*> animations;
     */
    float v_h_max;
    float v_h_act;
    float acc_h;
    float v_v_act;
    bool enLAir;
    bool goesLeft;
    unsigned nbBiere;
    Bonus *bonus;
    Touches touches;
    Body body;
    Grappin grappin;
};


#endif //MJAM2017_PERSO_HPP
