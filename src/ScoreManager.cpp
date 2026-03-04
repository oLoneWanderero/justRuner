#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

void ScoreManager::load()
{
    scores.clear();
    std::ifstream in(filename);
    if (!in.is_open())
        return;

    std::string line;
    while (getline(in, line))
    {
        std::stringstream ss(line);
        std::string name;
        int score;
        if (getline(ss, name, ',') && ss >> score)
        {
            scores.push_back({name, score});
        }
    }
    in.close();
}

void ScoreManager::save()
{
    std::ofstream out(filename, ios::app);
    for (ScoreEntry &s : scores)
    {
        out << s.name << "," << s.score << "\n";
    }
    out.close();
}

void ScoreManager::sortScores()
{
    sort(scores.begin(), scores.end(), [](const ScoreEntry &a, const ScoreEntry &b)
         { return b.score < a.score; });
}

ScoreManager::ScoreManager(string file) : filename{file}
{
    load();
}

void ScoreManager::addScore(string name, int score)
{
    vector<ScoreEntry>::iterator it = find_if(scores.begin(), scores.end(), [&](const ScoreEntry &e)
                                              { return e.name == name; });
    if (it != scores.end())
    {
        if (score > it->score)
        {
            it->score = score;
        }
        else
        {
            return;
        }
    }else{
        scores.push_back({name,score});
    }
    sortScores();
    save();
}
void ScoreManager::printTop(int limit)
{
    sortScores();
    cout << "===== High Scores =====" << endl;
    for (int i = 0; i < min(limit, (int)scores.size()); ++i)
    {
        cout << i + 1 << ". " << scores[i].name << " - " << scores[i].score << endl;
    }
    cout << "=======================" << endl;
}