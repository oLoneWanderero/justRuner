#include "Obstacle.h"

Obstacle::Obstacle(int startX,int StartY):x{startX},y{StartY}{}

void Obstacle::move(){
    x--;
}
int Obstacle::getX(){return x;}
int Obstacle::getY(){return y;}