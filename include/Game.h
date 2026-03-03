#pragma once
#include "Player.h"
#include "Field.h"
#include "ObstacleManager.h"
class Game
{
private:
    Player player;
    Field field;
    bool isRunning;
    ObstacleManager obstacleManager;
    int score;
    
    void gameLoop();
    void processInput();
    void update();
    void render();

public:
    Game();
    void run();
};