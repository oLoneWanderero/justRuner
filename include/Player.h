#pragma once
#include <string>
using namespace std;
class Player
{
private:
    int x;
    int y;
    int groundY;
    bool isJumping;
    int jumpCounter;
    int maxJump;
    string name;

public:
    Player();
    void update();
    void jump();
    int getX();
    int getY();
    void reset();
    void setName(string newName);
    string getName();
};
