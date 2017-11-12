#include "Biere.hpp"


Biere::Biere(int x, int y):
   Body(x, y, BIERE_WIDTH, BIERE_HEIGHT) {}


Biere::Biere() {
   fprintf(stderr, "Et une Biere de construite !\n");
}
