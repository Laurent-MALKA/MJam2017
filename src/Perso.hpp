#ifndef MJAM2017_PERSO_HPP
#define MJAM2017_PERSO_HPP

#include <SDL2/SDL_system.h>
#include <vector>
#include "Touches.hpp"
#include "Bonus.hpp"
#include "Body.hpp"
#include "Animation.hpp"

#define GRAP_WIDTH     10
#define GRAP_HEIGHT    10

#define GRAP_S_RETRACTE 0
#define GRAP_S_LANCE    1
#define GRAP_S_ACCROCHE 2
#define GRAP_S_RETOUR   3

#define GRAP_BASESPEED  3

#define GRAP_MAX_LENGTH 9

class Perso;
class Bonus;

class Grappin: public Body {
public:
   Grappin();
   Grappin(Perso * p, bool spc);

   void lancer();
   void bouger();
   void relacher();

   void stop();

    int getEtat() const;

private:
   int     etat;
   int     vit;
   int     len;
   bool    goesLeft;
   bool    estSpecial;
   Perso * p;
};

class Perso: public Body {

public:
    Perso(): Body(0,0,0,0), touches(SDL_NUM_SCANCODES,SDL_NUM_SCANCODES,SDL_NUM_SCANCODES,SDL_NUM_SCANCODES,SDL_NUM_SCANCODES){}
    Perso(SDL_Texture *spriteSheet,std::vector<Animation*> *animations,Body body, Touches touches);
    ~Perso();

    void bouger();

    const Touches &getTouches() const;

    void setAcc_h(float acc_h);

    void setV_v_act(float v_v_act);
    void setEnLAir(bool enLAir);
    void setColleMur(bool colleMur);
    void setAnimation(int i);
    void setBonus(Bonus *bonus);
    void setV_h_act(float v_h);

    Bonus* getBonus() const;
    float getV_v_act() const;
    float getAcc_h() const;
    bool isEnLAir() const;
    bool isColleMur() const;
    bool isGoingLeft() const;
    Grappin getGrappin() const;
    bool hasBonus();

    void update();
    void display(SDL_Renderer *rdr);
    void saut();
    void lancerGrappin();
    void lancerBonus();

private:
    SDL_Texture *spriteSheet;
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
