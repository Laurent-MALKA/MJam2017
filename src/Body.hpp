#ifndef MJAM2017_BODY_HPP
#define MJAM2017_BODY_HPP

class Body {
public:
   Body(int x, int y, int w, int h);

   void setX(int newX);
   void setY(int newY);
   void setW(int newW);
   void setH(int newH);

   int getX();
   int getY();
   int getW();
   int getH();

   bool collides(Body other);

private:
   int xywh[4];
};


#endif //MJAM2017_BODY_HPP