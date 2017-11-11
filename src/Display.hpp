#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Perso.hpp"
#include "Map.hpp"

class Display {
public:
   Display(int sdlFlags, int imgFlags, char * winName);
   ~Display();

    SDL_Renderer *getRenderer();

   bool initSDL(int sdlFlags, int imgFlags);

   bool isInitialized();

   void display(Perso *p1, Perso *p2,Map map);

   void scrolling(int x, int y);



private:
   SDL_Window   * win;
   SDL_Renderer * rdr;

   SDL_Rect rect;

   bool isInit;

   unsigned windowWidth;
   unsigned windowHeight;

   /* Fonts */

   /* Textures */
   Image background;
};

#endif
