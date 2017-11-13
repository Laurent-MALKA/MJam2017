#include "main.h"

int main(void) {
   SDL_Window   * window;
   SDL_Renderer * renderer;
   SDL_Event      event;

   int flags = IMG_INIT_JPG | IMG_INIT_PNG;

/* DEFINITION DES OBJETS */
   data_t data;

/* INITIALISATION DE SDL2 */
   if (SDL_Init(SDL_INIT_VIDEO) == 1) {
      fprintf(stderr, "failed to initialize SDL : %s\n", SDL_GetError());
      return EXIT_FAILURE;
   }


/* INITIALISATION DE SDL_image */
   if((IMG_Init(flags)&flags) != flags) {
       printf("IMG_Init: Failed to init required jpg and png support!\n");
       printf("IMG_Init: %s\n", IMG_GetError());
       TTF_Quit();
       SDL_Quit();
       return EXIT_FAILURE;
   }

/* CREATION DE LA FENETRE */
   window = SDL_CreateWindow(
      "fenetre de jeu",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
      0
   );

   if (!window) {
      fprintf(stderr, "failed to create window : %s\n", SDL_GetError());
      SDL_Quit();
      return EXIT_FAILURE;
   }

/* CREATION DU RENDERER */
   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

   if (!renderer) {
      fprintf(stderr, "failed to create renderer : %s\n", SDL_GetError());
      SDL_DestroyWindow(window);
      SDL_Quit();
      return EXIT_FAILURE;
   }

/* CREATION DES OBJETS */
   initData(renderer, &data);

/* BOUCLE D'EVENEMENTS */
   while (data.run) {
   /* EVENEMENTS */
      while (SDL_PollEvent(&event)) {
         switch (event.type) {
            case SDL_QUIT:
               data.run = 0;
               break;
         }
      }

      SDL_RenderClear(renderer);
      aff(renderer, data);


      /*showBackground(background);*/
      SDL_RenderPresent(renderer);

   /* DELAI */
      SDL_Delay(100);
   }


/* SORTIE DE PROGRAMME */
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   IMG_Quit();
   SDL_Quit();

   return EXIT_SUCCESS;
}

/******************************************************************************/
/******************************************************************************/

void initData(SDL_Renderer * rdr, data_t * pd) {
   FILE * pf = fopen("map0.txt", "r");
   int i = 0;
   int s;
   if (!pf) {
      printf("err1\n");
   } else {
      do {
         fscanf(pf, "%d", &s);
         pd->lst[i].x = s;
         fscanf(pf, "%d", &s);
         pd->lst[i].y = s;
         fscanf(pf, "%d", &s);
         pd->lst[i].w = s;
         fscanf(pf, "%d\n", &s);
         pd->lst[i].h = s;
         ++i;
      } while (!feof(pf));

      printf("1. done: %d\n", i);
      fclose(pf);
   }

   pd->run = 1;



   pf = fopen("checkpoints.txt", "r");
   if (!pf) {
      printf("err2\n");
   } else {
      i = 0;
      do {
         fscanf(pf, "%d", &s);
         pd->tab[i].x = s;
         fscanf(pf, "%d\n", &s);
         pd->tab[i].y = s;
         pd->tab[i].h = 5;
         pd->tab[i].w = 5;
         ++i;
      } while (!feof(pf));

      printf("2. done: %d\n", i);
      fclose(pf);
   }


   pf = fopen("biereTab.txt", "r");
   if (!pf) {
      printf("err3\n");
   } else {
      i = 0;
      do {
         fscanf(pf, "%d", &s);
         pd->bie[i].x = s;
         fscanf(pf, "%d\n", &s);
         pd->bie[i].y = s;
         pd->bie[i].h = 10;
         pd->bie[i].w = 5;
         ++i;
      } while (!feof(pf));

      printf("3. done: %d\n", i);
      fclose(pf);
   }
}


void aff(SDL_Renderer * rdr, data_t d) {
   int i;
   SDL_Rect rect;

   SDL_SetRenderDrawColor(rdr, 70, 70, 70, 0);
   SDL_RenderClear(rdr);
   rect.x = rect.y = 0;
   rect.w = WINDOW_WIDTH;
   rect.y = WINDOW_HEIGHT;
   SDL_RenderFillRect(rdr, &rect);

   for (i = 0; i < 53; ++i) {
      SDL_SetRenderDrawColor(rdr, 240, 0, 0, 0);
      SDL_RenderFillRect(rdr, &(d.lst[i]));
      SDL_SetRenderDrawColor(rdr, 0, 0, 0, 0);
      SDL_RenderDrawRect(rdr, &(d.lst[i]));
   }

   SDL_SetRenderDrawColor(rdr, 0, 200, 0, 0);
   for (i = 0; i < 200; ++i) {
      SDL_RenderFillRect(rdr, &(d.tab[i]));
   }

   SDL_SetRenderDrawColor(rdr, 20, 180, 180, 0);
   for (i = 0; i < 7; ++i) {
      SDL_RenderFillRect(rdr, &(d.bie[i]));
   }
}




// #include <stdio.h>
// #include <stdlib.h>
//
// int main() {
//    FILE * pf_r = fopen("map0.txt", "r");
//    FILE * pf_w = fopen("map1.txt", "w");
//    int x, y, w, h;
//
//    if (!pf_r || !pf_w) {
//       printf("erreur\n");
//    } else {
//       printf("truc\n");
//       do {
//          fscanf(pf_r, "%d", &x);
//          fscanf(pf_r, "%d", &y);
//          fscanf(pf_r, "%d", &w);
//          fscanf(pf_r, "%d", &h);
//          printf("%d ", x);
//
//          fprintf(pf_w, "%5d ", 3*x);
//          fprintf(pf_w, "%5d ", 3*y);
//          fprintf(pf_w, "%5d ", 3*w);
//          fprintf(pf_w, "%5d\n", 3*h);
//       } while (!feof(pf_r));
//
//       fclose(pf_r);
//       fclose(pf_w);
//    }
//
//    return 0;
// }
