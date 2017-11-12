#include <iosfwd>
#include <string>
#include <fstream>
#include "Map.hpp"
#include "Perso.hpp"
#include "main.hpp"

Map::Map() {
    initObstacles();
}

Map::~Map() = default;

void Map::testCollisions(std::vector<Perso*> p, int checkpoints[NB_CHECKPOINTS][2]) {
    int y;

   p[0]->desajust();
   p[1]->desajust();



    for (int i = 0; i < 2; i++) {
        p[i]->setColleMur(false);
        p[i]->setEnLAir(true);

        for (auto &obstacle: obstacles) {
            y= -1;
            if(estEnColision(*p[i], obstacle)) {

                if(p[i]->isEnLAir() && obstacle.getY()>=p[i]->getY() && obstacle.getY()<=p[i]->getY()+p[i]->getH() /*|| p[i]->getY()>=obstacle.getY() && p[i]->getY()<=obstacle.getY()+obstacle.getH())*/){
                    p[i]->setEnLAir(false);
                }

                if (obstacle.getY() < p[i]->getY()) {
                    if (obstacle.getX() < p[i]->getX()) {
                        if (obstacle.getX()+obstacle.getW() - p[i]->getX() > obstacle.getY()+obstacle.getH() - p[i]->getY()) {
                            p[i]->setY(obstacle.getY() + obstacle.getH()+5);
                            p[i]->setV_v_act(0);
                        } else {
                            p[i]->setX(obstacle.getX() + obstacle.getW());
                            p[i]->setColleMur(true);
                        }
                    } else {
                        if (p[i]->getX()+p[i]->getW()-obstacle.getX()  > obstacle.getY()+obstacle.getH() - p[i]->getY()) {
                            p[i]->setY(obstacle.getY() + obstacle.getH()+5);
                        } else {
                            p[i]->setX(obstacle.getX() - p[i]->getW());
                            p[i]->setColleMur(true);
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
                            p[i]->setColleMur(true);
                        }
                    }
                    else{
                        if(p[i]->getX()+p[i]->getW()-obstacle.getX()>p[i]->getY()+p[i]->getH()-obstacle.getY()){
                            p[i]->setY(obstacle.getY()-p[i]->getH());
                        }
                        else{
                            p[i]->setColleMur(true);
                            p[i]->setX(obstacle.getX()-p[i]->getW());
                        }
                    }
                }
                /*
                if (p[i]->getGrappin().getEtat() == GRAP_S_LANCE && estEnColision(p[i]->getGrappin(), obstacle)) {
                    p[i]->getGrappin().stop();
                }
                 */
                if (p[i]->hasBonus() && p[i]->getBonus()->isUtilise() && estEnColision(*p[i]->getBonus(), obstacle)) {
                    p[i]->resetBonus(nullptr);
                }
            }
        }

        if (p[i]->hasBonus() && p[i]->getBonus()->isUtilise() && estEnColision(*p[(i+1)%2], *p[i]->getBonus())) {
            p[i]->resetBonus(p[(i+1)%2]);
        }
        if(p[i]->getX()-checkpoints[p[i]->getCheckpointAct()][0]<20 && (p[i]->getY()>=checkpoints[p[i]->getCheckpointAct()][2] && p[i]->getY()<=checkpoints[p[i]->getCheckpointAct()][1] || checkpoints[p[i]->getCheckpointAct()][2]>=p[i]->getY() && checkpoints[p[i]->getCheckpointAct()][2]<=p[i]->getY()+p[i]->getH())){
            p[i]->setCheckpointAct(p[i]->getCheckpointAct()+1);
        }

   }

   p[0]->reajust();
   p[1]->reajust();

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
    for (auto obstacle : obstacles) {
        SDL_Rect rect_d = {obstacle.getX()-map_rect.x+WINDOW_WIDTH/2,obstacle.getY()-map_rect.y+WINDOW_HEIGHT/2,obstacle.getW(),obstacle.getH()};
        SDL_SetRenderDrawColor(rdr,102,51,0,0);
        SDL_RenderFillRect(rdr,&rect_d);
        SDL_SetRenderDrawColor(rdr,0,0,0,0);
        SDL_RenderDrawRect(rdr,&rect_d);

        SDL_Rect rect_i = {rect_d.x,rect_d.y,rect_d.w,20};
        SDL_SetRenderDrawColor(rdr,0,96,15,0);
        SDL_RenderFillRect(rdr,&rect_i);
        SDL_SetRenderDrawColor(rdr,0,0,0,0);
        SDL_RenderDrawRect(rdr,&rect_i);
    }
}
