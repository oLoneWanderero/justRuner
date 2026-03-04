#pragma once
#include <string>
#include <vector>
using namespace std;

struct ScoreEntry
{
    string name;
    int score;
};

class ScoreManager{
    private:
    string filename;
    vector<ScoreEntry> scores;
    void load();
    void save();
    void sortScores();
    public:
    ScoreManager(string file);
    void addScore(string name,int score);
    void printTop(int limit=10);
};