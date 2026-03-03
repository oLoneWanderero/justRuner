#pragma once
#include "Player.h"
#include "Obstacle.h"
#include <vector>
#include <string>
using namespace std;

class Field
{
private:
    int width;
    int height;
    vector<string> buffer;

public:
    Field();
    void clear();
    void drawPlayer(Player player);
    void render();
    int getWidth();
    int getHeight();
    void drawObstacles( vector<Obstacle> &obstacles);
};