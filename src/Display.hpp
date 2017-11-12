#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <cstdio>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Perso.hpp"
#include "Map.hpp"
#include "main.hpp"
#include "Biere.hpp"

class Map;

class Display {
public:
   Display(int sdlFlags, int imgFlags, char * winName);
   ~Display();

    SDL_Renderer *getRenderer();

   bool initSDL(int sdlFlags, int imgFlags);

   bool isInitialized();

   void displayBiere(Biere b);

   void display(Perso *p1, Perso *p2,Map map, int checkpoints[NB_CHECKPOINTS][2]);

   void scrolling(int x, int y);


private:
   SDL_Window   * win;
   SDL_Renderer * rdr;

   SDL_Rect map_rect;

   bool isInit;

   unsigned windowWidth;
   unsigned windowHeight;

   /* Fonts */

   /* Textures */
   Image background;
   Image biere;

   SDL_Texture *titre;
   SDL_Rect titre_rect;
};

#endif
