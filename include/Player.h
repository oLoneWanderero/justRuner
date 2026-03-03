#pragma once
class Player
{
private:
    int x;
    int y;
    int groundY;
    bool isJumping;
    int jumpCounter;
    int maxJump;

public:
    Player();
    void update();
    void jump();
    int getX();
    int getY();
    void reset();
};
