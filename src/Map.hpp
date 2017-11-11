#ifndef MJAM2017_MAP_HPP
#define MJAM2017_MAP_HPP


class Map {
public:
    Map();
    ~Map();
    void testCollisions(Perso p);

private:
    void initObstacles();

    Obstacle* obstacles;

};


#endif //MJAM2017_MAP_HPP
