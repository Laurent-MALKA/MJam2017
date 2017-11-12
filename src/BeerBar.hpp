#ifndef MJAM2017_BEERBAR_HPP
#define MJAM2017_BEERBAR_HPP


#include <SDL2/SDL_render.h>
#include "Body.hpp"

class BeerBar : public Body {
public:
    BeerBar() = default;
    BeerBar(int x,int y) : Body(x,y,100,20), level(50) {}

    int getLevel();

    void grabBeer();

    void update();

    void display(SDL_Renderer *rdr);

private:
    double level;
};


#endif //MJAM2017_BEERBAR_HPP
