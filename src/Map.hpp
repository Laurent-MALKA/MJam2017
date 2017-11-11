#ifndef MJAM2017_MAP_HPP
#define MJAM2017_MAP_HPP


#include "Perso.hpp"
#include "Obstacle.hpp"

class Map {
public:
    Map();
    ~Map();
    void initObstacles();

    void testCollisions(std::vector<Perso*> p);
private:
    bool estEnColision(Body p, Obstacle obstacle);
    std::vector<Obstacle> obstacles;

    bool estEnColision2(Perso p, Body b);
};


#endif //MJAM2017_MAP_HPP
