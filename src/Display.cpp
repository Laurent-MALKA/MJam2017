#include <iostream>
#include "Display.hpp"
#include "Perso.hpp"
#include "Map.hpp"

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

            /* creation des images */
            this->background = Image(this->rdr, const_cast<char *>("assets/map.png"));
            this->background.setDimension(WINDOW_WIDTH*3, WINDOW_HEIGHT*3);

            this->biere = Image(this->rdr, const_cast<char *>("assets/biere.png"));

            //this->wormhole = Image(this->rdr, const_cast<char *>("assets/wormhole.png"));

            TTF_Font *font = TTF_OpenFont("assets/FEASFBRG.TTF",150);
            SDL_Color color = {0,0,0,0};
            SDL_Surface *t_surface = TTF_RenderText_Blended(font,"Kroforce",color);
            titre = SDL_CreateTextureFromSurface(rdr,t_surface);
            SDL_FreeSurface(t_surface);

            titre_rect.x = 290;
            titre_rect.y = 200;
            titre_rect.w = 400;
            titre_rect.h = 150;

            SDL_Surface *t_surface2 = IMG_Load("assets/fleche.png");
            fleche = SDL_CreateTextureFromSurface(rdr,t_surface2);
            SDL_FreeSurface(t_surface);

            fleche_rect.x=350;
            fleche_rect.y=370;
            fleche_rect.w=200;
            fleche_rect.h=120;
         }
      }
   }
   map_rect.x = 0;
   map_rect.y = 0;
   map_rect.w = WINDOW_WIDTH;
   map_rect.y = WINDOW_HEIGHT;
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
   if (SDL_Init(static_cast<Uint32>(sdlFlags)) == 1) {
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
   this->isInit &= this->win != nullptr && this->rdr != nullptr;

   return this->isInit;
}


void Display::displayBiere(Biere b) {
   SDL_Rect rect;
   rect.x = b.getX();
   rect.y = b.getY();
   rect.w = b.getW();
   rect.h = b.getH();

   if (b.isActive())
   SDL_RenderCopy(this->rdr, this->biere.getTexture(), NULL, &rect);
}


void Display::display(Perso *p1, Perso *p2,Map map, int checkpoints[NB_CHECKPOINTS][2], Biere bTab[NB_BIERES]) {
   SDL_SetRenderDrawColor(rdr,50,50,50,0);
   SDL_RenderClear(rdr);
   map.display(rdr,map_rect);
   SDL_SetRenderDrawColor(rdr,0,0,255,0);

    scrolling((p1->getX()+p1->getW()/2 + p2->getX()+p2->getW()/2)/2,(p1->getY()+p1->getH()/2 + p2->getY()+p1->getW()/2)/2);

   SDL_Rect tmp_rect;
   tmp_rect.x = titre_rect.x - map_rect.x + WINDOW_WIDTH/2;
   tmp_rect.y = titre_rect.y - map_rect.y + WINDOW_HEIGHT/2;
   tmp_rect.w = titre_rect.w;
   tmp_rect.h = titre_rect.h;
   SDL_RenderCopy(rdr,titre, nullptr,&tmp_rect);

   tmp_rect.x = fleche_rect.x - map_rect.x + WINDOW_WIDTH/2;
   tmp_rect.y = fleche_rect.y - map_rect.y + WINDOW_HEIGHT/2;
   tmp_rect.w = fleche_rect.w;
   tmp_rect.h = fleche_rect.h;
   SDL_RenderCopy(rdr,fleche, nullptr,&tmp_rect);
   for (int i = 0; i < NB_BIERES; ++i) {
      // printf("%d:%d:%d:%d\n", bTab[i].getX(), bTab[i].getY(), bTab[i].getW(), bTab[i].getH());
      bTab[i].inc(-map_rect.x + WINDOW_WIDTH/2, -map_rect.y + WINDOW_HEIGHT/2);
      displayBiere(bTab[i]);
      bTab[i].dec(-map_rect.x + WINDOW_WIDTH/2, -map_rect.y + WINDOW_HEIGHT/2);
   }

   p1->display(rdr,map_rect);
   p2->display(rdr,map_rect);



   SDL_RenderPresent(this->rdr);
}

void Display::scrolling(int x, int y) {
   if(x < WINDOW_WIDTH/2)
      map_rect.x = WINDOW_WIDTH/2;
   else if(x > MAP_WIDTH-WINDOW_WIDTH/2)
      map_rect.x = MAP_WIDTH-WINDOW_WIDTH/2;
   else
      map_rect.x = x;
   if(y < WINDOW_HEIGHT/2)
      map_rect.y = WINDOW_HEIGHT/2;
   else if(y > MAP_HEIGHT-WINDOW_HEIGHT/2)
      map_rect.y = MAP_HEIGHT-WINDOW_HEIGHT/2;
   else
      map_rect.y = y;
}

SDL_Renderer *Display::getRenderer() {
   return rdr;
}

/*
SDL_Texture *Display::getWormhole() const {
    return whormhole;
}
 */
