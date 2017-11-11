#ifndef MJAM2017_MAP_HPP
#define MJAM2017_MAP_HPP


#include "Perso.hpp"
#include "Obstacle.hpp"

class Map {
public:
    Map();
    ~Map();
    void initObstacles();

    void testCollisions(std::vector<Perso*> p, int checkpoints[11][3]);
private:
    bool estEnColision(Body p, Body obstacle);
    std::vector<Obstacle> obstacles;
};


#endif //MJAM2017_MAP_HPP
