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
    bool SpacePressed;
    bool quitToMenu;
    int frameDelay;
    int scoreMultiplier;

    void gameLoop();
    void processInput();
    void update();
    void render();

public:
    Game(int difficulty,string playerName);
    void run();
    bool isQuitToMenu(){return quitToMenu;}
};