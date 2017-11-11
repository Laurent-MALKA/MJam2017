#ifndef MJAM2017_AniMATION_HPP
#define MJAM2017_AniMATION_HPP


#include <SDL2/SDL_system.h>
#include <vector>

class Animation {
public:
    Animation() = default;

    Animation(int x, int y, int w, int h, int count, float speed);

    void update();

    SDL_Rect getRect();


private:
    float frame{};
    float speed{};
    std::vector<SDL_Rect> frames;
};


#endif //MJAM2017_AniMATION_HPP
