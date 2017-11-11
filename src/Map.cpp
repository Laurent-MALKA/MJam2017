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

void Map::testCollisions(std::vector<Perso*> p, int checkpoints[11][3]) {
    int y;
    for (int i = 0; i < 2; i++) {
        p[i]->setColleMur(false);

        for (auto &obstacle: obstacles) {
            y= -1;
            if(estEnColision(*p[i], obstacle)) {
                if (p[i]->getY() < obstacle.getY() && p[i]->getY() + p[i]->getW() < obstacle.getY() + obstacle.getW()) {
                    p[i]->setColleMur(true);
                }
                if(p[i]->isEnLAir() && (obstacle.getY()>=p[i]->getY() && obstacle.getY()<=p[i]->getY()+p[i]->getH() || p[i]->getY()>=obstacle.getY() && p[i]->getY()<=obstacle.getY()+obstacle.getH())){
                    p[i]->setEnLAir(false);
                }
                if (obstacle.getY() < p[i]->getY()) {
                    y = obstacle.getY() + obstacle.getH();
                } else {
                    y = obstacle.getY()-p[i]->getH();
                }

                if (obstacle.getX() < p[i]->getX()) {
                    p[i]->setX(obstacle.getX() + obstacle.getW());
                } else {
                    p[i]->setX(obstacle.getX()-p[i]->getW());
                }
                if (y != -1) {
                    p[i]->setY(y);
                }

                if (p[i]->getGrappin().getEtat() == GRAP_S_LANCE && estEnColision(p[i]->getGrappin(), obstacle)) {
                    p[i]->getGrappin().stop();
                }
                if (p[i]->getBonus() != NULL && p[i]->getBonus()->getUtilise() == 1 && estEnColision(*p[i]->getBonus(), obstacle)) {
                    p[i]->getBonus()->mort(NULL);
                }
            }
        }

        if (p[i]->getBonus() != NULL && p[i]->getBonus()->getUtilise() == 1 && estEnColision(*p[(i+1)%2], *p[i]->getBonus())) {
            p[i]->getBonus()->mort(p[(i+1)%2]);
        }
        if(p[i]->getX()-checkpoints[p[i]->getCheckpointAct()][0]<20 && (p[i]->getY()>=checkpoints[p[i]->getCheckpointAct()][2] && p[i]->getY()<=checkpoints[p[i]->getCheckpointAct()][1] || checkpoints[p[i]->getCheckpointAct()][2]>=p[i]->getY() && checkpoints[p[i]->getCheckpointAct()][2]<=p[i]->getY()+p[i]->getH())){
            p[i]->setCheckpointAct(p[i]->getCheckpointAct()+1);
        }

    }
}

void Map::initObstacles() {
    std::string line;
    std::ifstream file;
    file.open("assets/map1.txt",std::ios::in);
    if(file.is_open()) {
        int x, y, w, h;

        while (!file.eof()) {
            file >> x;
            file >> y;
            file >> w;
            file >> h;
            obstacles.emplace_back(x, y, w, h);
        }
    }
}

bool Map::estEnColision(Body p, Body obstacle){
    return	(obstacle.getX()>=p.getX() && obstacle.getX()<=p.getX()+p.getW() || p.getX()>=obstacle.getX() && p.getX()<=obstacle.getX()+obstacle.getW())
           &&
           (obstacle.getY()>=p.getY() && obstacle.getY()<=p.getY()+p.getH() || p.getY()>=obstacle.getY() && p.getY()<=obstacle.getY()+obstacle.getH())
            ;

}