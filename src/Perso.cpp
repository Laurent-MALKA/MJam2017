#include <fstream>
#include "Perso.hpp"

Perso::Perso(SDL_Texture * spriteSheet,std::vector<Animation*> *animations, Body body, Touches touches):
   Body(body), v_h_max(10.0),
   v_h_act(0),
   acc_h(0),
   v_v_act(0),
   enLAir(false), goesLeft(true), colleMur(false),
   nbBiere(0), bonus(), touches(touches), grappin(this,false) {
   this->spriteSheet = spriteSheet;
   this->animations = animations;
    animation = (*animations)[0];
    checkpointAct=0;

    int x;
    std::ifstream file;
    file.open("checkpoints", std::ios::in);
    for(int i=0; i<11; i++){
        file>>x;
        checkpoints[i/3][i%3]=x;

    }
}

//Test collision et changement position dans Moteur
void Perso::bouger(){
    float vitesse=acc_h+v_h_act+nbBiere/2;

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

    setX(int(getX()+v_h_act));

    if(getGrappin().getEtat()!=GRAP_S_RETRACTE){
        getGrappin().bouger();
    }
    if(bonus!=NULL && bonus->getUtilise()){
        bonus->bouger();
    }
}

void Perso::saut(){
    setY(int(getY()-v_v_act));
    v_v_act-=0.8;
}

Grappin Perso::getGrappin() const{
    return grappin;
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

float Perso::getAcc_h() const{
    return acc_h;
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

bool Perso::hasBonus() {
    return bonus != NULL;
}

void Perso::setBonus(Bonus *bonus) {
    this->bonus = bonus;
}

void Perso::lancerBonus() {
    bonus->effet();
}

Perso::~Perso() {
    delete animation;
    delete bonus;
    if(spriteSheet)
        SDL_DestroyTexture(spriteSheet);
}

float Perso::getV_v_act() const {
    return v_v_act;
}

void Perso::display(SDL_Renderer *rdr,SDL_Rect rect) {
    SDL_Rect dstrect = {getX() - rect.x+WINDOW_WIDTH/2,getY() - rect.y+WINDOW_HEIGHT/2,getW(),getH()};
    SDL_Rect srcrect = animation->getRect();
    SDL_RendererFlip flip = (!goesLeft) ? SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE;
    SDL_RenderCopyEx(rdr,spriteSheet,&srcrect,&dstrect,0,NULL,flip);
}

Bonus* Perso::getBonus() const {
    return bonus;
}

void Perso::setV_h_act(float v_h) {
    v_h_act=v_h;
}

int Perso::getCheckpointAct() const {
    return checkpointAct;
}

void Perso::setCheckpointAct(int checkpointAct) {
    Perso::checkpointAct = checkpointAct%12;
}
