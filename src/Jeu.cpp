#include <fstream>
#include "Jeu.hpp"

Jeu::Jeu():inputs(), moteur(), display(SDL_INIT_VIDEO,IMG_INIT_PNG,(char *)"C'est quoi le nom ?") {

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
    std::vector<Animation*> animation;
    animation.push_back(new Animation(0,0,512/4,512/4,4,0.1));

    p1= new Perso(spriteSheet,&animation,Body(300,300,75,75),Touches(SDL_SCANCODE_A,SDL_SCANCODE_D,SDL_SCANCODE_W,SDL_SCANCODE_Q,SDL_SCANCODE_E));
    p2= new Perso(spriteSheet,&animation,Body(300,315,75,75),Touches(SDL_SCANCODE_K,SDL_SCANCODE_SEMICOLON,SDL_SCANCODE_O,SDL_SCANCODE_I,SDL_SCANCODE_P));

    int x;
    std::ifstream file;
    file.open("checkpoints", std::ios::in);
    for(int i=0; i<NB_CHECKPOINTS*2; i++){
        file>>x;
        checkpoints[i/2][i%2]=x;

    }
}

Jeu::~Jeu() {
    delete p1;
    //delete p2;
}
