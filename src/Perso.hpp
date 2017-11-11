#ifndef MJAM2017_PERSO_HPP
#define MJAM2017_PERSO_HPP


#include <SDL2/SDL_system.h>
#include <vector>
#include "Touches.hpp"
#include "Bonus.hpp"
#include "Body.hpp"
#include "Grappin.hpp"
#include "Animation.hpp"

class Grappin;

class Perso: public Body {

public:
    Perso(SDL_Texture *tileset,std::vector<Animation*> *animations,Body body, Touches touches);

    const Touches &getTouches() const;

    void setAcc_h(float acc_h);

    void setV_v_act(float v_v_act);
    void setEnLAir(bool enLAir);
    void setColleMur(bool colleMur);
    void setAnimation(int i);

    bool isEnLAir() const;
    bool isColleMur() const;
    bool isGoingLeft() const;

    void update();
    void deplacement();
    void saut();
    void lancerGrappin();

private:
    SDL_Texture *tileset;
    Animation *animation;
    std::vector<Animation*> *animations;
    float v_h_max;
    float v_h_act;
    float acc_h;
    float v_v_act;
    bool enLAir;
    bool goesLeft;
    bool colleMur;
    unsigned nbBiere;
    Bonus *bonus;
    Touches touches;
    Body body;
    Grappin grappin;
};


#endif //MJAM2017_PERSO_HPP
