#ifndef MJAM2017_BODY_HPP
#define MJAM2017_BODY_HPP

#define BD_DIFF 18

class Body {
public:
   Body(int x, int y, int w, int h);

    Body();

   void setX(int newX);
   void setY(int newY);
   void setW(int newW);
   void setH(int newH);

   void setPosition(int x, int y);

   void inc(int dx, int dy);
   void dec(int dx, int dy);

   int getX();
   int getY();
   int getW();
   int getH();

   void desajust();
   void reajust();

   bool collides(Body other);

   double distance(Body other);

private:
   int xywh[4];
};


#endif //MJAM2017_BODY_HPP
