#include "Perso.hpp"

Perso::Perso(SDL_Texture * tileset,std::vector<Animation*> *animations, Body body, Touches touches): v_h_max(10.0),
                                                                                                     v_h_act(0),
                                                                                                     acc_h(0),
                                                                                                     v_v_act(0),
                                                                 enLAir(false), goesLeft(true), colleMur(false),
                                                                 nbBiere(0), bonus(), touches(touches), grappin(this,false),
                                                                 body(body) {
    this->tileset = tileset;
    this->animations = animations;
}

//Test collision et changement position dans Moteur
void Perso::deplacement(){
    float vitesse=acc_h+v_h_act;

    /*Décélération*/
    if(vitesse<0){
        if(vitesse>-1.0)
            vitesse=0;
        else
            vitesse++;
    }
    else if(vitesse>0){
        if(vitesse<1.0)
            vitesse=0;
        else
            vitesse--;
    }

    /*vitesse>vitesse max*/
    if(vitesse>v_h_max) {
        vitesse = v_h_max;
    }
    else if(vitesse<-v_h_max){
        vitesse=-v_h_max;
    }

    v_h_act=vitesse;

    body.setX(int(body.getX()+v_h_act));
}

void Perso::saut(){
    body.setY(int(body.getY()-v_v_act));
    v_v_act-=1;
}

const Touches &Perso::getTouches() const {
    return touches;
}

void Perso::setAcc_h(float acc_h) {
    if(acc_h > 0)
        goesLeft = true;
    else if(acc_h < 0)
        goesLeft = false;
    this->acc_h = acc_h;
}

void Perso::setV_v_act(float v_v_act) {
    this->v_v_act = v_v_act;
}

bool Perso::isEnLAir() const {
    return enLAir;
}

void Perso::setEnLAir(bool enLAir) {
    this->enLAir = enLAir;
}

bool Perso::isGoingLeft() const {
    return goesLeft;
}

bool Perso::isColleMur() const {
    return colleMur;
}

void Perso::setColleMur(bool colleMur) {
    Perso::colleMur = colleMur;
}

void Perso::lancerGrappin() {
    grappin.lancer();
}

void Perso::update() {
    animation->update();
}

void Perso::setAnimation(int i) {
    animation = (*animations)[i];
    animation->reset();
}
