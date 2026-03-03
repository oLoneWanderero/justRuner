#include "Field.h"
#include <iostream>
using namespace std;

Field::Field() : width{30}, height{10}
{
    buffer.resize(height, string(width, ' '));
}

void Field::clear()
{
    for (string &row : buffer)
    {
        row.assign(width, ' ');
    }
}
void Field::drawPlayer(Player player)
{
    int x = player.getX();
    int row = height - 1 - player.getY();
    if (row >= 0 && row < height && x >= 0 && x < width)
    {
        buffer[row][x] = 'P';
    }
}
void Field::drawObstacles(vector<Obstacle> &obstacles)
{
    for (Obstacle &obs : obstacles)
    {
        int row = height - 1 - obs.getY();
        int x = obs.getX();
        if (row >= 0 && row < height && x >= 0 && x < width)
        {
            buffer[row][x] = '|';
        }
    }
}

void Field::render()
{
    for (string row : buffer)
    {
        cout << row << endl;
    }
}
int Field::getWidth() { return width; }
int Field::getHeight() { return height; }