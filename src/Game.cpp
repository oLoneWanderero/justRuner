#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Input.h"
#include "Game.h"
using namespace std;

Game::Game(int diff,string playerName) : obstacleManager{30, 5}, score{0}, isRunning{true}, SpacePressed{false}, quitToMenu{false}
{
    setNonBlocking(true);
    player.setName(playerName);
    switch (diff)
    {
    case 1:
        obstacleManager.setSpawnRate(8);
        frameDelay = 250;
        scoreMultiplier = 1;
        break;
    case 2:
        obstacleManager.setSpawnRate(5);
        frameDelay = 200;
        scoreMultiplier = 2;
        break;
    case 3:
        obstacleManager.setSpawnRate(3);
        frameDelay = 150;
        scoreMultiplier = 3;
        break;
    default:
        obstacleManager.setSpawnRate(5);
        frameDelay = 200;
        scoreMultiplier = 2;
    }
}

void Game::run()
{
    gameLoop();
    setNonBlocking(false);
}

void Game::gameLoop()
{
    while (isRunning)
    {
        processInput();
        update();
        render();
        this_thread::sleep_for(chrono::milliseconds(frameDelay));
    }
}
void Game::processInput()
{
    if (kbhit())
    {
        char c = getchar();

        if (c == 'q')
        {
            quitToMenu = true;
            isRunning = false;
            return;
        }
        else if (c == ' ' && player.getY() == 0)
        {
            player.jump();
        }

        int extra;
        while (kbhit() && (extra = getchar()) != EOF)
        {
        }
    }
}
void Game::update()
{
    player.update();
    obstacleManager.update();
    if (obstacleManager.checkCollision(player.getX(), player.getY()))
    {
        isRunning = false;
    }
    score+=scoreMultiplier;
}
void Game::render()
{
    system("clear");
    field.clear();
    field.drawPlayer(player);
    field.drawObstacles(obstacleManager.getObstacles());
    field.render();
    cout << "Score: " << score << endl;
    cout<<"Player: "<<player.getName()<<endl;
}