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
    else if(vitesse<-v_max){
        vitesse=-v_h_max;
    }

    v_h_act=vitesse;

    body.x=body.x+v_h_act;
}

void Perso::saut(){
    body.y=body.y-v_v_act;
    v_v_act-=1;
}