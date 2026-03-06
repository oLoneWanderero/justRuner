#pragma once
#include <string>
using namespace std;
class Score
{
    private:
    string player;
    int bestScore;
    public:
    Score();
    Score(string name,int score);
    string getPlayer();
    int getScore();
    void updateIfHigher(int score);
};