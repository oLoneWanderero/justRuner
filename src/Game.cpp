#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Input.h"
#include "Game.h"
using namespace std;

Game::Game() : obstacleManager{30, 3}, score{0}, isRunning{true}, SpacePressed{false}
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

        if (c == 'q')
        {
            isRunning = false;
        }
        else if (c == ' '  && player.getY() == 0)
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