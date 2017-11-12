#ifndef __BIERE_HPP__
#define __BIERE_HPP__

#include <cstdio>

#include "Body.hpp"

#define BIERE_WIDTH  50
#define BIERE_HEIGHT 50

class Biere: public Body {
public:
   Biere(int x, int y);
   Biere();
};

#endif
