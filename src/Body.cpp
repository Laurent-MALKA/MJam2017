#include "Body.hpp"

Body::Body(int x, int y, int w, int h):
   xywh{x, y, w, h} {}


void Body::setX(int newX) {
   this->xywh[0] = newX;
}

void Body::setY(int newY) {
   this->xywh[1] = newY;
}

void Body::setW(int newW) {
   this->xywh[2] = newW;
}

void Body::setH(int newH) {
   this->xywh[3] = newH;
}


int Body::getX() {
   return this->xywh[0];
}

int Body::getY() {
   return this->xywh[1];
}

int Body::getW() {
   return this->xywh[2];
}

int Body::getH() {
   return this->xywh[3];
}


bool Body::collides(Body other) {
   return !(
      this->getX() + this->getW() < other->getX()
   || this->getY() + this->getH() < other->getY()
   || other->getX() + other->getW() < this->getX()
   || other->getY() + other->getH() < this->getY()
   );
}