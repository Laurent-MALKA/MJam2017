#ifndef MJAM2017_JEU_HPP
#define MJAM2017_JEU_HPP


#include "Inputs.hpp"
#include "Moteur.hpp"
#include "Display.hpp"
#include "Map.hpp"

class Jeu {
public:
    Jeu();
    void gameloop();

private:
    Inputs inputs;
    Moteur moteur;
    Display display;
    Map map;
    Perso p1;
    Perso p2;

};


#endif //MJAM2017_JEU_HPP
