#pragma once
#include "Player.h"
#include "Field.h"
#include "ObstacleManager.h"
class Game
{
private:
    Player player;
    Field field;
    ObstacleManager obstacleManager;
    int score;
    bool isRunning;
    bool wasSpacePressed;

    void gameLoop();
    void processInput();
    void update();
    void render();

public:
    Game();
    void run();
};