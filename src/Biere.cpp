#include "Biere.hpp"


Biere::Biere(int x, int y):
   Body(x, y, BIERE_WIDTH, BIERE_HEIGHT) {}


Biere::Biere() {
   fprintf(stderr, "c'est pas ce contructeur qu'il faut utiliser !\n");
}
