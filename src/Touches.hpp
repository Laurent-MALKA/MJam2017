#ifndef MJAM2017_TOUCHES_HPP
#define MJAM2017_TOUCHES_HPP


#include <SDL2/SDL_scancode.h>

class Touches {
public:
    Touches(SDL_Scancode t_gauche, SDL_Scancode t_droite, SDL_Scancode t_saut,
            SDL_Scancode t_grappin, SDL_Scancode t_bonus);

    SDL_Scancode getT_gauche() const;

    SDL_Scancode getT_droite() const;

    SDL_Scancode getT_saut() const;

    SDL_Scancode getT_grappin() const;

    SDL_Scancode getT_bonus() const;

private:
    SDL_Scancode t_gauche;
    SDL_Scancode t_droite;
    SDL_Scancode t_saut;
    SDL_Scancode t_grappin;
    SDL_Scancode t_bonus;

};


#endif //MJAM2017_TOUCHES_HPP
