#include "Jeu.hpp"

Jeu::Jeu():inputs(), moteur(), display(SDL_INIT_VIDEO,IMG_INIT_PNG,"Hello World!") {

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

            if (p1->getV_v_act() != 0) {
                p1->saut();
            }
            if (p2->getV_v_act() != 0) {
                p2->saut();
            }

            map.testCollisions(p1);
            map.testCollisions(p2);

            display.display(p1,p2);
            SDL_Delay(16);
            fin = inputs.exit();
        }
        init();
    }
}

void Jeu::init(){
    SDL_Surface *surface = IMG_Load("assets/spritesheet-demo.png");
    SDL_Texture *spriteSheet = SDL_CreateTextureFromSurface(display.getRenderer(),surface);
    SDL_FreeSurface(surface);
    std::vector<Animation*> animation;
    animation.push_back(new Animation(0,0,40,43,6,0.2));

    p1= new Perso(spriteSheet,&animation,Body(100,100,100,100),Touches(SDL_SCANCODE_A,SDL_SCANCODE_D,SDL_SCANCODE_W,SDL_SCANCODE_Q,SDL_SCANCODE_E));
    p2= new Perso(spriteSheet,&animation,Body(120,120,100,100),Touches(SDL_SCANCODE_K,SDL_SCANCODE_SEMICOLON,SDL_SCANCODE_O,SDL_SCANCODE_I,SDL_SCANCODE_P));
}
