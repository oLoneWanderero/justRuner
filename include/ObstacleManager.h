#pragma once
#include "Obstacle.h"
#include <vector>
using namespace std;
class ObstacleManager
{
private:
    vector<Obstacle> obstacles;
    int width;
    int height;
    int spawnCounter;
    int spawnRate;

public:
    ObstacleManager(int fieldWidth, int fieldHeight);
    void update();
    vector<Obstacle> &getObstacles();
    bool checkCollision(int plaerX, int playerY);
};
