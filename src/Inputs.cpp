#include "Inputs.hpp"

Inputs::Inputs() {
    keyboard = (Uint8 *) SDL_GetKeyboardState(nullptr);
    currentState = (bool *) malloc(SDL_NUM_SCANCODES * sizeof(bool));
    previousState = (bool *) malloc(SDL_NUM_SCANCODES * sizeof(bool));

    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        *(currentState + i) = keyboard[i];
        *(previousState + i) = false;
    }
}

Inputs::~Inputs() {
    free(currentState);
    free(previousState);
}

void Inputs::update() {
    SDL_PumpEvents();
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        *(previousState + i) = *(currentState + i);
        *(currentState + i) = keyboard[i];
    }
}

bool Inputs::isStillPressed(SDL_Scancode scancode) const {
    return previousState[scancode] && currentState[scancode];
}

bool Inputs::isStillReleased(SDL_Scancode scancode) const {
    return !previousState[scancode] && !currentState[scancode];
}

bool Inputs::isJustPressed(SDL_Scancode scancode) const {
    return !previousState[scancode] && currentState[scancode];
}

bool Inputs::isJustReleased(SDL_Scancode scancode) const {
    return previousState[scancode] && !currentState[scancode];
}

bool Inputs::isStillPressed(int scancode) const {
    return previousState[scancode] && currentState[scancode];
}

bool Inputs::isStillReleased(int scancode) const {
    return !previousState[scancode] && !currentState[scancode];
}

bool Inputs::isJustPressed(int scancode) const {
    return !previousState[scancode] && currentState[scancode];
}

bool Inputs::isJustReleased(int scancode) const {
    return previousState[scancode] && !currentState[scancode];
}

bool Inputs::isKeyboardReleased() {
    bool out = true;
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        if (*(currentState + i))
            out = false;
    }

    return out;
}

void Inputs::analyseInputs(Perso* p){
    if(p->getCptRebond()==0 && (isStillPressed(p->getTouches().getT_droite()) && isStillPressed(p->getTouches().getT_gauche()) || isStillReleased(p->getTouches().getT_droite()) && isStillReleased(p->getTouches().getT_gauche()))){
        p->setAcc_h(0);
    }
    else if(isStillPressed(p->getTouches().getT_droite()) && p->getCptRebond()==0){
        p->setAcc_h(2);
    }
    else if(isStillPressed(p->getTouches().getT_gauche()) && p->getCptRebond()==0){
        p->setAcc_h(-2);
    }
    if(isStillPressed(p->getTouches().getT_saut()) && !p->isEnLAir()){
        p->setV_v_act(15);
        p->saut();
        p->setEnLAir(true);
    }/*
    if(isJustPressed(p->getTouches().getT_grappin()) && p->getGrappin().getEtat()){
        p->lancerGrappin();
    }*/

    if(isJustPressed(p->getTouches().getT_bonus()) && p->hasBonus()){
        p->lancerBonus();
    }
    if(isJustPressed(p->getTouches().getT_saut()) && p->isColleMur() && p->isEnLAir()){
        int x=-10;
        if(p->isGoingLeft()){
            x=10;
        }
        p->setV_v_act(15);
        p->setAcc_h(3*x/10);
        p->setCptRebond(20);
    }
}

bool Inputs::exit() {
    bool out = false;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT)
            out = true;
    }
    return out;
}
