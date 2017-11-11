#include <iosfwd>
#include <string>
#include <fstream>
#include "Map.hpp"
#include "Perso.hpp"

Map::Map() {
    initObstacles();
}

Map::~Map() {

}

void Map::testCollisions(Perso *p){
    p->setColleMur(false);
    int y=-1;
    for(auto &obstacle: obstacles){
        if(	(obstacle.getX()>=p->getX() && obstacle.getX()<=p->getX()+p->getW() || p->getX()>=obstacle.getX() && p->getX()<=obstacle.getX()+obstacle.getW())
               &&
                (obstacle.getY()>=p->getY() && obstacle.getY()<=p->getY()+p->getH() || p->getY()>=obstacle.getY() && p->getY()<=obstacle.getY()+obstacle.getH())
                ){
            if(p->getY()<obstacle.getY() && p->getY()+p->getW()<obstacle.getY()+obstacle.getW()){
                p->setColleMur(true);
            }
            if(obstacle.getY()>p->getY()+p->getH()) {
                y=obstacle.getY()-p->getH();
            }
            else if(obstacle.getY()<p->getY()){
                y=obstacle.getY()+obstacle.getH();
            }

            if(obstacle.getX()>p->getX()+p->getW()) {
                p->setX(obstacle.getX());
            }
            else if(obstacle.getX()<p->getX()){
                p->setX(obstacle.getX()+obstacle.getW());
            }
            if(y!=-1){
                p->setY(y);
            }
        }
    }
}

void Map::initObstacles() {
    std::string line;
    std::ifstream file;
    file.open("assets/map1.txt",std::ios::in);
    if(file.is_open()) {
        int x, y, w, h;

        while (file.tellg() < file.end) {
            file >> x;
            file >> y;
            file >> w;
            file >> h;
            obstacles.emplace_back(x, y, w, h);
        }
    }
}