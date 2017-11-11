#include "Display.hpp"

Display::Display(int sdlFlags, int imgFlags, char * winName):
   isInit(false),
   windowWidth(WINDOW_WIDTH),
   windowHeight(WINDOW_HEIGHT) {
   if (!this->initSDL(sdlFlags, imgFlags)) {
      fprintf(stderr, "erreur initialisation SDL\n");
   } else {
      this->win = SDL_CreateWindow(
         winName,
         SDL_WINDOWPOS_CENTERED,
         SDL_WINDOWPOS_CENTERED,
         this->windowWidth,
         this->windowHeight,
         0
      );

      if (!this->win) {
         fprintf(stderr, "erreur creation de la fenetre\n");
      } else {
         this->rdr = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED);

         if (!this->rdr) {
            fprintf(stderr, "erreur creation du renderer\n");
         } else {
            this->isInit = true;
         }
      }
   }
}


Display::~Display() {
   if (this->rdr)
      SDL_DestroyRenderer(this->rdr);

   if (this->win)
      SDL_DestroyWindow(this->win);

   TTF_Quit();
   IMG_Quit();
   SDL_Quit();

   this->isInit = false;
}


bool Display::initSDL(int sdlFlags, int imgFlags) {
   if (SDL_Init(sdlFlags) == 1) {
      fprintf(stderr, "SDL2: Failed to initialize SDL : %s\n", SDL_GetError());
      return false;
   }

   if((IMG_Init(imgFlags)&imgFlags) != imgFlags) {
       printf("IMG_Init: Failed to init flags\n");
       printf("IMG_Init: %s\n", IMG_GetError());
       SDL_Quit();
       return false;
   }

   if (TTF_Init() != 0) {
       fprintf(stderr, "TTF_Init: Failed to initialize TTF : %s\n", TTF_GetError());
       SDL_Quit();
       return false;
   }

   return true;
}


bool Display::isInitialized() {
   this->isInit &= this->win != NULL && this->rdr != NULL;

   return this->isInit;
}


void Display::display() {
   SDL_RenderPresent(this->rdr);
}

void Display::scrolling(int x, int y) {
   if(x < WINDOW_WIDTH/2)
      rect.x = WINDOW_WIDTH/2;
   else if(x > MAP_WIDTH-WINDOW_WIDTH/2)
      rect.x = MAP_WIDTH-WINDOW_WIDTH/2;
   else
      rect.x = x;
   if(y < WINDOW_HEIGHT/2)
      rect.y = WINDOW_HEIGHT/2;
   else if(y > MAP_HEIGHT-WINDOW_HEIGHT/2)
      rect.y = MAP_HEIGHT-WINDOW_HEIGHT/2;
   else
      rect.y = y;
}

SDL_Renderer *Display::getRenderer() {
   return rdr;
}
