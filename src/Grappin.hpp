#ifndef MJAM2017_GRAPPIN_HPP
#define MJAM2017_GRAPPIN_HPP

#include "Body.hpp"
#include "Perso.hpp"

#define GRAP_S_RETRACTE 0
#define GRAP_S_LANCE    1
#define GRAP_S_ACCROCHE 2
#define GRAP_S_RETOUR   3

#define GRAP_BASESPEED  3

class Grappin {
public:
   Grappin(Perso * p, bool spc);

   int getX();
   int getY();

   void lancer();
   int  bouger();
   void relacher();

private:
   Body    pos;
   Body    acc;
   int     etat;
   int     vit;
   bool    goesLeft;
   bool    estSpecial;
   Perso * p;
};


#endif //MJAM2017_GRAPPIN_HPP
