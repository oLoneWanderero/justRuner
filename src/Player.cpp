#include <Player.h>

Player::Player() : x{2}, y{0}, groundY{0}, isJumping{false}, jumpCounter{0},maxJump{3} {}

void Player::jump()
{
    if (!isJumping&&y==groundY)
    {
        isJumping = true;
        jumpCounter = maxJump;
    }
}
void Player::update()
{
    if (isJumping)
    {
        if (y < maxJump)
            y++;
        jumpCounter--;
        if (jumpCounter <= 0)
            isJumping = false;
    }
    else if (y > groundY)
    {
        y--;
    }
}

int Player::getX()
{
    return x;
}
int Player::getY()
{
    return y;
}
void Player::reset(){
    y=groundY;
    isJumping=false;
}