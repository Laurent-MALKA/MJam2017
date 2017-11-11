#include "Perso.hpp"

Perso::Perso(Body body, Touches touches): v_h_max(10.0), v_h_act(0), v_h_accG(0), v_h_accD(0), v_v_act(0), enLAir(false), nbBiere(0), bonus(), touches(touches), grappin(), body(body){

}

//Test collision et changement position dans Moteur
void Perso::deplacement(){
    float vitesse=v_h_accD+v_h_accG+v_h_act;

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

void Perso::setV_h_accG(float v_h_accG) {
    Perso::v_h_accG = v_h_accG;
}

void Perso::setV_h_accD(float v_h_accD) {
    Perso::v_h_accD = v_h_accD;
}

void Perso::setV_v_act(float v_v_act) {
    Perso::v_v_act = v_v_act;
}

bool Perso::isEnLAir() const {
    return enLAir;
}
