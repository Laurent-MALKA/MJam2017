#include "Map.hpp"
#include "Perso.hpp"

Map::Map() {
    initObstacles();
}

Map::~Map() {

}

void Map::testCollisions(Perso p){
    p.setColleMur(false);
    for(auto &obstacle: obstacles){
        if(	(obstacle.getX()>=p.getX() && obstacle.getX()<=p.getX()+p.getW() || p.getX()>=obstacle.getX() && p.getX()<=obstacle.getX()+obstacle.getW())
               &&
                (obstacle.getY()>=p.getY() && obstacle.getY()<=p.getY()+p.getH() || p.getY()>=obstacle.getY() && p.getY()<=obstacle.getY()+obstacle.getH())
                ){
            if(obstacle.getY()>p.getY()+p.getH()) {
                p.setY(obstacle.getY()+obstacle.);
            }
            else if(obstacle.getY()>p.getY()){
                p.setY(obstacle.getY()+obstacle.getH());
            }

            if(obstacle.getX()>p.getX()+p.getW()) {
                p.setX(obstacle.getX());
            }
            else if(obstacle.getX()>p.getX()){
                p.setX(obstacle.getX()+obstacle.getW());
            }
        }
    }
}

void Map::initObstacles() {

}