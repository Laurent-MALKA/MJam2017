#include "Touches.hpp"

Touches::Touches(SDL_Scancode t_gauche, SDL_Scancode t_droite,
                 SDL_Scancode t_saut, SDL_Scancode t_grappin, SDL_Scancode t_bonus) : t_gauche(t_gauche),
                                                                                      t_droite(t_droite),
                                                                                      t_saut(t_saut),
                                                                                      t_grappin(t_grappin),
                                                                                      t_bonus(t_bonus) {}

SDL_Scancode Touches::getT_gauche() const {
    return t_gauche;
}

SDL_Scancode Touches::getT_droite() const {
    return t_droite;
}

SDL_Scancode Touches::getT_saut() const {
    return t_saut;
}

SDL_Scancode Touches::getT_grappin() const {
    return t_grappin;
}

SDL_Scancode Touches::getT_bonus() const {
    return t_bonus;
}
