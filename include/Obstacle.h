#pragma once

class Obstacle
{
private:
    int x;
    int y;
public:
    Obstacle(int startX,int startY);
    void move();
    int getX();
    int getY();
};