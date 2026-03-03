#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Input.h"
#include "Game.h"
using namespace std;

Game::Game() : isRunning{true}, obstacleManager{30, 3}, score{0}
{
    setNonBlocking(true);
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
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}
void Game::processInput()
{
    if (kbhit())
    {
        char c = getchar();
        if(c=='\n'){
            return;
        }
        if (c == 'q')
        {
            isRunning = false;
        }
        else{
            player.jump();
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
    score++;
}
void Game::render()
{
    system("clear");
    field.clear();
    field.drawPlayer(player);
    field.drawObstacles(obstacleManager.getObstacles());
    field.render();
    cout << "Score: " << score << endl;
}