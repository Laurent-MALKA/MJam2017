#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700

class Display {
public:
   Display(int sdlFlags, int imgFlags, char * winName, int ts);
   ~Display();

   bool initSDL(int sdlFlags, int imgFlags);

   bool isInitialized();

   void display();

private:
   SDL_Window   * win;
   SDL_Renderer * rdr;

   bool isInit;

   unsigned windowWidth;
   unsigned windowHeight;

   /* Fonts */

   /* Textures */
};

#endif
