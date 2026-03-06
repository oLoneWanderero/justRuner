#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <Score.h>
using namespace std;


class ScoreManager{
    private:
    string filename;
    unordered_map<string,Score> scores;
    void load();
    void save();
    public:
    ScoreManager(string file);
    void addScore(string name,int score);
    void printTop(int limit=10);
};