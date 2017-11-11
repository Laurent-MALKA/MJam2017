#ifndef MJAM2017_MAP_HPP
#define MJAM2017_MAP_HPP


#include "Perso.hpp"
#include "Obstacle.hpp"

class Map {
public:
    Map();
    ~Map();
    void testCollisions(Perso p);

private:
    void initObstacles();

    std::vector<Obstacle> obstacles;

};


#endif //MJAM2017_MAP_HPP
