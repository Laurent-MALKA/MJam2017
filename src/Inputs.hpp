#ifndef MJAM2017_INPUTS_HPP
#define MJAM2017_INPUTS_HPP

#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_events.h>
#include "Perso.hpp"

class Inputs {
public:
    Inputs();

    ~Inputs();

    void update();

    bool isStillPressed(SDL_Scancode scancode) const;

    bool isStillReleased(SDL_Scancode scancode) const;

    bool isJustPressed(SDL_Scancode scancode) const;

    bool isJustReleased(SDL_Scancode scancode) const;

    bool isStillPressed(int scancode) const;

    bool isStillReleased(int scancode) const;

    bool isJustPressed(int scancode) const;

    bool isJustReleased(int scancode) const;

    bool isKeyboardReleased();

    void analyseInputs(Perso* p);

    bool exit();

private:
    Uint8 *keyboard;
    bool *currentState;
    bool *previousState;
    SDL_Event event;
};


#endif //MJAM2017_INPUTS_HPP
