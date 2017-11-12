#ifndef MJAM2017_JEU_HPP
#define MJAM2017_JEU_HPP

#include <cstdlib>
#include <ostream>

#include "Inputs.hpp"
#include "Moteur.hpp"
#include "Display.hpp"
#include "Map.hpp"
#include "Biere.hpp"


class Jeu {
public:
    Jeu();
    ~Jeu();
    void gameloop();

    bool ends();
    bool P1Wins();

private:
    void init();
    Inputs inputs;
    Moteur moteur;
    Display display;
    Map map;
    Perso* p1;
    Perso* p2;
    int checkpoints[NB_CHECKPOINTS][2];
    Biere biereTab[NB_BIERES];

    //std::vector<Body> bodies;
};


#endif //MJAM2017_JEU_HPP
