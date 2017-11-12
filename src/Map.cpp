#include <iosfwd>
#include <string>
#include <fstream>
#include "Map.hpp"
#include "Perso.hpp"

Map::Map() {
    initObstacles();
}

Map::~Map() = default;

void Map::testCollisions(std::vector<Perso*> p, int checkpoints[11][3]) {
    int y;
    for (int i = 0; i < 2; i++) {
        p[i]->setColleMur(false);
        p[i]->setEnLAir(true);

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
                    if (obstacle.getX() < p[i]->getX()) {
                        if (obstacle.getX()+obstacle.getW() - p[i]->getX() > obstacle.getY()+obstacle.getH() - p[i]->getY()) {
                            p[i]->setY(obstacle.getY() + obstacle.getH()+5);
                        } else {
                            p[i]->setX(obstacle.getX() + obstacle.getW());
                        }
                    } else {
                        if (p[i]->getX()+p[i]->getW()-obstacle.getX()  > obstacle.getY()+obstacle.getH() - p[i]->getY()) {
                            p[i]->setY(obstacle.getY() + obstacle.getH()+5);
                        } else {
                            p[i]->setX(obstacle.getX() - p[i]->getW());
                        }
                    }
                }
                else {
                    if (obstacle.getX() < p[i]->getX()) {
                        if(obstacle.getX()+obstacle.getW()-p[i]->getX()>p[i]->getY()+p[i]->getH()-obstacle.getY()){
                            p[i]->setY(obstacle.getY()-p[i]->getH());
                        }
                        else{
                            p[i]->setX(obstacle.getX()+obstacle.getW());
                        }
                    }
                    else{
                        if(p[i]->getX()+p[i]->getW()-obstacle.getX()>p[i]->getY()+p[i]->getH()-obstacle.getY()){
                            p[i]->setY(obstacle.getY()-p[i]->getH());
                        }
                        else{
                            p[i]->setX(obstacle.getX()-p[i]->getW());
                        }
                    }
                }

                if (p[i]->getGrappin().getEtat() == GRAP_S_LANCE && estEnColision(p[i]->getGrappin(), obstacle)) {
                    p[i]->getGrappin().stop();
                }
                if (p[i]->getBonus() != nullptr && p[i]->getBonus()->getUtilise() == 1 && estEnColision(*p[i]->getBonus(), obstacle)) {
                    p[i]->getBonus()->mort(nullptr);
                }
            }
        }

        if (p[i]->getBonus() != nullptr && p[i]->getBonus()->getUtilise() == 1 && estEnColision(*p[(i+1)%2], *p[i]->getBonus())) {
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

void Map::display(SDL_Renderer *rdr,SDL_Rect map_rect) {
    SDL_SetRenderDrawColor(rdr,255,0,0,0);
    for (auto obstacle : obstacles) {
        SDL_Rect rect_d = {obstacle.getX()-map_rect.x+WINDOW_WIDTH/2,obstacle.getY()-map_rect.y+WINDOW_HEIGHT/2,obstacle.getW(),obstacle.getH()};
        SDL_RenderFillRect(rdr,&rect_d);
    }
}
