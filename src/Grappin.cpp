// #include "Grappin.hpp"
#include "Perso.hpp"

Grappin::Grappin(Perso * p, bool spc):
   Body(0, 0, GRAP_WIDTH, GRAP_HEIGHT),
   etat(GRAP_S_RETRACTE),
   vit(GRAP_BASESPEED),
   len(0),
   goesLeft(true),
   estSpecial(spc) {
   this->p = p;
}

Grappin::Grappin():
Grappin(NULL, false) {}

void Grappin::lancer() {
   this->setX(this->p->getX());
   this->setY(this->p->getY());
   this->etat = GRAP_S_LANCE;
   this->goesLeft = this->p->isGoingLeft();
   this->len = 0;
}

void Grappin::bouger() {
   switch (this->etat) {
      case GRAP_S_LANCE:
         ++this->len;
         if (this->estSpecial) {
            if (this->goesLeft) {
               this->inc(-this->vit, -this->vit);
            } else {
               this->inc(this->vit, -this->vit);
            }
         } else {
            if (this->goesLeft) {
               this->inc(-this->vit, 0);
            } else {
               this->inc(this->vit, 0);
            }
         }
         break;
      case GRAP_S_RETOUR:
         --this->len;
         this->setX(this->p->getX());
         this->setY(this->p->getY());
         this->etat = GRAP_S_RETRACTE;
         break;
   }
}


void Grappin::stop() {
   if (this->etat == GRAP_S_LANCE) {
      this->etat = GRAP_S_ACCROCHE;
      this->len = 0;
   }
}

void Grappin::relacher() {
   if (this->etat == GRAP_S_ACCROCHE) {
      this->etat = GRAP_S_RETOUR;
   }
}

int Grappin::getEtat() const {
    return etat;
}