#include "Image.hpp"

Image::Image():
   rdr(NULL),
   img(NULL) {
}

Image::Image(SDL_Renderer * rdr, char * str, int x, int y):
   rdr(rdr) {
   SDL_Surface * s = IMG_Load(str.c_str());
   this->img = SDL_CreateTextureFromSurface(rdr, s);

   this->rct.x = x;
   this->rct.y = y;
   this->rct.w = s->w;
   this->rct.h = s->h;

   SDL_FreeSurface(s);
}

Image::~Image() {
   SDL_DestroyTexture(this->img);
}

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

void Image::display() {
   SDL_RenderCopy(this->rdr, this->img, NULL, &this->rct);
}
