#ifndef __BIERE_HPP__
#define __BIERE_HPP__

#include <cstdio>

#include "Body.hpp"

#define BIERE_WIDTH  22
#define BIERE_HEIGHT 49

#define BIERE_TIME  45

class Biere: public Body {
public:
   Biere(int x, int y);
   Biere();

   void activer();
   void desactiver();
   bool isActive();

   void compter();

private:
   bool isA = true;
   int time = 0;
};

#endif
