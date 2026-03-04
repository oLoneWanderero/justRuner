#pragma once
#include <iostream>
#include <string>
using namespace std;

class Menu
{
private:
    int difficulty;
    string playerName;

public:
    Menu();
    void show();
    int getDifficulty();
    bool shouldExit();
    string getPlayerName();
};