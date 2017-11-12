#include "BeerBar.hpp"

int BeerBar::getLevel() {
    return int(level);
}

void BeerBar::grabBeer() {
    level += 20;
    if(level > 100)
        level = 100;
}

void BeerBar::update() {
    level -= 0.1;
    if(level < 0)
        level = 0;
}

void BeerBar::display(SDL_Renderer *rdr) {
    SDL_SetRenderDrawColor(rdr,255,0,0,0);
    SDL_Rect b_rect = {getX(),getY(),getW(),getH()};
    SDL_RenderFillRect(rdr,&b_rect);
    SDL_SetRenderDrawColor(rdr,0,255,0,0);
    SDL_Rect f_rect = {b_rect.x, b_rect.y, static_cast<int>(b_rect.w * level / 100),b_rect.h};
    SDL_RenderFillRect(rdr,&f_rect);
}
