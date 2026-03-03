#include "ObstacleManager.h"
#include <cstdlib>
#include <ctime>

using namespace std;

ObstacleManager::ObstacleManager(int fieldWidth, int fieldHeight)
    : width{fieldWidth}, height{fieldHeight}, spawnCounter{0}, spawnRate{5} {
        srand(static_cast<unsigned>(time(nullptr)));
    }

void ObstacleManager::update()
{
    for (Obstacle &obs : obstacles)
    {
        obs.move();
    }
    vector<Obstacle> newObstacles;
    for (Obstacle &obs : obstacles)
    {
        if (obs.getX() >= 0)
        {
            newObstacles.push_back(obs);
        }
    }
    obstacles = newObstacles;
    spawnCounter++;
    if (spawnCounter >= spawnRate)
    {
        spawnCounter = 0;
        int y = rand()%height;
        obstacles.emplace_back(width - 1, y);
        //spawnRate = 3+ (rand()%5);
    }
}
vector<Obstacle>&ObstacleManager::getObstacles(){
    return obstacles;
}
bool ObstacleManager::checkCollision(int playerX,int playerY){
    for(Obstacle&obs:obstacles){
        if(obs.getX()==playerX&&obs.getY()==playerY){
            return true;
        }
    }
    return false;
}