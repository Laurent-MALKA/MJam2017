#include "Jeu.hpp"

Jeu::Jeu():inputs(), moteur(), display(){

}

void Jeu::gameloop() {
    bool fin;

    while (keyboard.isStillReleased(SDL_SCANCODE_ESCAPE)) {
        fin = false;
        p1.getBody().setX();
        while (keyboard.isStillReleased(SDL_SCANCODE_ESCAPE) && !fin) {
            keyboard.update();

            inputs.analyseInputs(p1);
            inputs.analyseInputs(p1);

            p1.deplacements();
            p2.deplacements();

            if (p1.getV_v_act != 0)
                p1.saut();
            if (p2.getV_v_act != 0)
                p2.saut();

            display.affichage();
            SDL_Delay(16);
        }
    }
}