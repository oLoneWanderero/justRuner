#include "Score.h"

Score::Score() : player{""}, bestScore{0} {}
Score::Score(string name, int score) : player{name}, bestScore{score} {}
string Score::getPlayer()
{
    return player;
}
int Score::getScore()
{
    return bestScore;
}
void Score::updateIfHigher(int score)
{
    if (score > bestScore)
    {
        bestScore = score;
    }
}