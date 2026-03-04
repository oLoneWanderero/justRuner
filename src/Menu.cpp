#include "Menu.h"
#include "ScoreManager.h"
#include <iostream>
using namespace std;

Menu::Menu() : difficulty{2}, playerName{"Player"} {}

void Menu::show()
{
    bool exitMenu = false;
    while (!exitMenu)
    {
        system("clear");
        cout << "=========================" << endl;
        cout << "|       JustRunner      |" << endl;
        cout << "=========================" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Difficulty (Current: ";
        switch (difficulty)
        {
        case 1:
            cout << "Easy";
            break;
        case 2:
            cout << "Medium";
            break;
        case 3:
            cout << "Hard";
            break;
        }
        cout << ")" << endl;
        cout << "3. Enter Name (Current: " << playerName << ")" << endl;
        cout << "4. High Score" << endl;
        cout << "5. Exit" << endl;
        cout << "> ";

        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            exitMenu = true;
            break;
        case 2:
        {
            cout << "Select Difficulty (1-Easy, 2-Medium, 3-Hard): ";
            int diff;
            cin >> diff;
            if (diff >= 1 && diff <= 3)
                difficulty = diff;
            cin.ignore(1000, '\n');
            break;
        }
        case 3:
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, playerName);
            if (playerName.empty())
            {
                playerName = "Player";
            }
            break;
        case 4:
        {
            ScoreManager score("data/scores.csv");
            score.printTop(10);
            cin.ignore();
            cin.get();
            break;
        }
        case 5:
            exitMenu = true;
            difficulty = -1;
            break;
        }
    }
}

int Menu::getDifficulty() { return difficulty; }
bool Menu::shouldExit() { return difficulty == -1; }
string Menu::getPlayerName() { return playerName; }