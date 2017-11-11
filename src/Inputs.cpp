#include "Inputs.hpp"

Inputs::Inputs() {
    keyboard = (Uint8 *) SDL_GetKeyboardState(NULL);
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

void analyseInputs(Perso p1){
    if(isStillPressed(p1.getTouches().getT_droite()) && isStillPressed(p1.getTouches(à.getT_gauche()))){
        p1.setAcc(0);
    }
    else if(isStillPressed(p1.getTouches().getT_droite())){
        p1.setAcc_h(2);
    }
    else if(isStillPressed(p1.getTouches().getT_gauche())){
        p1.setAcc_h(-2);
    }
    if(isStillPressed(p1.getTouches().getT_saut()) && !p1.getEnLAir()){
        p1.setV_v_act=10;
        p1.setEnLAir(true);
    }
    if(isJustPressed(p1.getTouches().getT_grappin()) && !p1.getGrappin().isActif){
        p1.getGrappin().lancer();
        p1.getGrappin().setActif(true);
    }
    if(isStillPressed(p1.getTouches().getT_bonus()) && p1.getBonus()!=NULL){
        p1.getBonus.effet();
        p1.setBonus(NULL);
    }
    if(isStillPressed(p1.getTouches().getT_saut()) && p1.getColleMur()){
        int x=-1;
        if(p1.isGoingLeft()){
            x=1;
        }
        p1.setAcc_h(x*3);
    }
}
