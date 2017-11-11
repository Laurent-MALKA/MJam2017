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