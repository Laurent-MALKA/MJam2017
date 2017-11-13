#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* LISTE DES CONSTANTES */

/* DIVERS */
#define DISPLAY_DELAY   10
#define WINDOW_WIDTH  1123
#define WINDOW_HEIGHT  816

/* CODES CLAVIER */
#define KEY_ESC 27


typedef struct {
   int run;
   SDL_Rect lst[53];
   SDL_Rect tab[200];
   SDL_Rect bie[7];
} data_t;

void initData(SDL_Renderer * rdr, data_t * pd);

void aff(SDL_Renderer * rdr, data_t);
