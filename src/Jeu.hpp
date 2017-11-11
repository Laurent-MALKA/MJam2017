#ifndef MJAM2017_JEU_HPP
#define MJAM2017_JEU_HPP

#include "Inputs.hpp"
#include "Moteur.hpp"
#include "Display.hpp"
#include "Map.hpp"

class Jeu {
public:
    Jeu();
    ~Jeu();
    void gameloop();

private:
    void init();
    Inputs inputs;
    Moteur moteur;
    Display display;
    Map map;
    Perso* p1;
    Perso* p2;
    //std::vector<Body> bodies;
};


#endif //MJAM2017_JEU_HPP
