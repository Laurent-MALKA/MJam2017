#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <string>

class Image {
public:
   Image();
   Image(SDL_Renderer * rdr, char * str, int x, int y);
   ~Image();

   void setPosition(int x, int y);
   void setX(int x);
   void setY(int y);

   void display();

private:
   SDL_Renderer * rdr;
   SDL_Texture  * img;
   SDL_Rect       rct;
};

#endif
