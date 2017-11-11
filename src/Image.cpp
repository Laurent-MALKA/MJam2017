#include "Image.hpp"
#include "Perso.hpp"

Image::Image():
   rdr(nullptr),
   img(nullptr) {
}

Image::Image(SDL_Renderer * rdr, char * str, int x, int y):
   rdr(rdr) {
   SDL_Surface * s = IMG_Load(str);
   this->img = SDL_CreateTextureFromSurface(rdr, s);

   this->rct.x = x;
   this->rct.y = y;
   this->rct.w = s->w;
   this->rct.h = s->h;

   SDL_FreeSurface(s);
}

Image::~Image() = default;

void Image::setPosition(int x, int y) {
   this->setX(x);
   this->setY(y);
}

void Image::setX(int x) {
   this->rct.x = x;
}

void Image::setY(int y) {
   this->rct.y = y;
}

void Image::setDimension(int w, int h) {
   this->rct.w = w;
   this->rct.h = h;
}

void Image::display(SDL_Rect *rect) {
   SDL_Rect rect2 = {rect->x-WINDOW_WIDTH/2,rect->y - WINDOW_WIDTH/2,rect->w,rect->h};
   SDL_RenderCopy(this->rdr, this->img, &rect2, &(this->rct));
}
