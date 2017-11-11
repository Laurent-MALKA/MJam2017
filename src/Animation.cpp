#include "Animation.hpp"

Animation::Animation(int x, int y, int w, int h, int count, float speed) {
    frame = 0;
    this->speed = speed;
    
    for (int i = 0; i < count; ++i) {
        SDL_Rect rect = {(x+i)*w,y*h,w,h};
        frames.push_back(rect);
    }
}

void Animation::reset() {
    frame = 0;
}

void Animation::update() {
    frame += speed;
    const auto n = frames.size();
    if(frame > n)
        frame -= n;
}

SDL_Rect Animation::getRect() {
    return frames[(int)frame];
}

