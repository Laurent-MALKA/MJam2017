#include "Biere.hpp"


Biere::Biere(int x, int y):
   Body(x, y, BIERE_WIDTH, BIERE_HEIGHT) {}


Biere::Biere():
   Body() {

}


void Biere::activer() {
   this->isA = true;
}


void Biere::desactiver() {
   this->isA = false;
   this->time = 0;
}


bool Biere::isActive() {
   return this->isA;
}


void Biere::compter() {
   if (!this->isActive())
      ++this->time;

   if (this->time > BIERE_TIME)
      this->activer();
}
