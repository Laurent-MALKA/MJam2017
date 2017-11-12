#include <fstream>
#include <iostream>
#include "Jeu.hpp"

Jeu::Jeu():inputs(), moteur(), display(SDL_INIT_VIDEO,IMG_INIT_PNG,(char *)"Hello World !") {

    init();

    //bodies.pushBack(Perso(spriteSheet,&animation,Body(100,100,100,100),Touches(SDL_SCANCODE_A,SDL_SCANCODE_D,SDL_SCANCODE_W,SDL_SCANCODE_Q,SDL_SCANCODE_E)));
    //bodies.pushBack(Perso(spriteSheet,&animation,Body(120,120,100,100),Touches(SDL_SCANCODE_K,SDL_SCANCODE_SEMICOLON,SDL_SCANCODE_O,SDL_SCANCODE_I,SDL_SCANCODE_P)));
}

void Jeu::gameloop() {
    bool fin = false;

    while (inputs.isStillReleased(SDL_SCANCODE_ESCAPE) && !fin) {
        fin = false;
        while (inputs.isStillReleased(SDL_SCANCODE_ESCAPE) && !fin) {
            inputs.update();
            p1->update();
            p2->update();

            inputs.analyseInputs(p1);
            inputs.analyseInputs(p2);

            p1->bouger();
            p2->bouger();

            if (p1->isEnLAir()) {
                p1->saut();
            }
            if (p2->isEnLAir()) {
                p2->saut();
            }

            std::vector<Perso*> pP;
            pP.push_back(p1);
            pP.push_back(p2);
            map.testCollisions(pP,checkpoints);

            for (int i = 0; i < NB_BIERES; ++i) {
               if (p1->collides(biereTab[i])) {
                  p1->grabBeer();
               }
               if (p2->collides(biereTab[i])) {
                  p2->grabBeer();
               }
            }

////////////////////////////////////////////////////////////////////////////////

            if (ends()) {
                TTF_Font *font = TTF_OpenFont("assets/arial.ttf",50);
                SDL_Surface *vainqueur_surf = TTF_RenderText_Solid(font,(P1Wins() ? "P1 Wins" : "P2 Wins"),{0,0,0,0});
                SDL_Texture *vainqueur_text = SDL_CreateTextureFromSurface(display.getRenderer(),vainqueur_surf);
                SDL_FreeSurface(vainqueur_surf);
                SDL_Rect vainqueur_rect;
                vainqueur_rect.w = WINDOW_WIDTH*3/4;
                vainqueur_rect.h = 150;
                vainqueur_rect.x = WINDOW_WIDTH/2 - vainqueur_rect.w/2;
                vainqueur_rect.y = WINDOW_HEIGHT/2 - vainqueur_rect.h/2;
               SDL_RenderCopy(display.getRenderer(),vainqueur_text, nullptr,&vainqueur_rect);
                SDL_RenderPresent(display.getRenderer());
                SDL_Delay(1000);
                init();
            }

////////////////////////////////////////////////////////////////////////////////

            display.display(p1,p2,map,checkpoints, biereTab);
            SDL_Delay(16);
            fin = inputs.exit();
        }
        init();
    }
}

void Jeu::init(){
    SDL_Surface *surface = IMG_Load("assets/spritesheet.png");
    SDL_Texture *spriteSheet = SDL_CreateTextureFromSurface(display.getRenderer(),surface);
    SDL_FreeSurface(surface);

    SDL_Surface *surface2 = IMG_Load("assets/spritesheet2.png");
    SDL_Texture *spriteSheet2 = SDL_CreateTextureFromSurface(display.getRenderer(),surface2);
    SDL_FreeSurface(surface2);

    std::vector<Animation*> animation;
    animation.push_back(new Animation(0,0,512/4,512/4,4,0.1));

    p1= new Perso(spriteSheet,&animation,Body(300,300,75,75),Touches(SDL_SCANCODE_A,SDL_SCANCODE_D,SDL_SCANCODE_W,SDL_SCANCODE_Q,SDL_SCANCODE_E),0,0);
    p2= new Perso(spriteSheet2,&animation,Body(300,315,75,75),Touches(SDL_SCANCODE_K,SDL_SCANCODE_SEMICOLON,SDL_SCANCODE_O,SDL_SCANCODE_I,SDL_SCANCODE_P),WINDOW_WIDTH-100,0);

    int x, y;
    std::ifstream file;
    file.open("assets/checkpoints.txt", std::ios::in);
    if(file.is_open()) {
        for (int i = 0; i < NB_CHECKPOINTS * 2; i++) {
            file >> x;
            checkpoints[i / 2][i % 2] = x*3;
        }
    } else {
        std::cerr << "NTM:non" << std::endl;
    }

    file.close();

    file.open("assets/biereTab.txt", std::ios::in);
    std::cout << x << ":" << y << std::endl;
    if(file.is_open()) {
        for (int i = 0; i < NB_BIERES; i++) {
            file >> x;
            file >> y;
            std::cout << x << ":" << y << std::endl;
            biereTab[i] = Biere(x*3, y*3);
        }
    } else {
        std::cerr << "NTM:non" << std::endl;
    }

    file.close();
}

Jeu::~Jeu() {
    delete p1;
    //delete p2;
}

bool Jeu::ends() {
   return abs(p1->getX() - p2->getX()) > WINDOW_WIDTH
   || abs(p1->getY() - p2->getY()) > WINDOW_HEIGHT;
}

bool Jeu::P1Wins() {
   int c1 = 0;
   int c2 = 0;
   int d1 = WINDOW_WIDTH;
   int d2 = WINDOW_WIDTH;
   int tmp1, tmp2;

   for (int i = 0; i < NB_CHECKPOINTS; ++i) {
      Body checkpoint(checkpoints[i][0],checkpoints[i][1],0,0);
      tmp1 = checkpoint.distance(*p1);
      tmp2 = checkpoint.distance(*p2);
      if (tmp1 < d1) {
         c1 = i;
         d1 = tmp1;
      }
      if (tmp2 < d2) {
         c2 = i;
         d2 = tmp2;
      }
   }

   std::cout << c1 << ":" << c2 << std::endl;

   return abs(c2-c1) < 90 ? c1 > c2 : c1 < c2;
}
