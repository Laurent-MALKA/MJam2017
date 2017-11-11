#include "Map.hpp"

Map::Map() {
    initObstacles();
}

Map::~Map() {

}

void Map::testCollisions(Perso p){
    p.setColleMur(false);
    for(auto &obstacle: obstacles){
        if(	(obstacle->getBody().getX()>=p.getBody().getX() && obstacle->getBody().getX()<=p.getBody().getX()+p.getBody().getWidth() || p.getBody().getX()>=obstacle->getBody().getX() && p.getBody().getX()<=obstacle->getBody().getX()+obstacle->getBody().getWidth())
               &&
                (obstacle->getBody().getY()>=p.getBody().getY() && obstacle->getBody().getY()<=p.getBody().getY()+p.getBody().getHeight() || p.getBody().getY()>=obstacle->getBody().getY() && p.getBody().getY()<=obstacle->getBody().getY()+obstacle->getBody().getHeight())
                ){
            if(obstacle->getBody().getY()>p.getBody().getY()+p.getBody().getHeight()) {
                p.getBody().setY(obstacle->getBody().getY()+obstacle->);
            }
            else if(obstacle->getBody().getY()>p.getBody().getY()){
                p.getBody().setY(obstacle->getBody().getY()+obstacle->getBody().getHeight());
            }

            if(obstacle->getBody().getX()>p.getBody().getX()+p.getBody().getWidth()) {
                p.getBody().setX(obstacle->getBody().getX());
            }
            else if(obstacle->getBody().getX()>p.getBody().getX()){
                p.getBody().setX(obstacle->getBody().getX()+obstacle->getBody().getWidth());
            }
        }
    }
}

void Map::initObstacles() {

}