#include "ScoreManager.h"
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager(string file) : filename{file}
{
    load();
}

void ScoreManager::load()
{
    scores.clear();
    ifstream in(filename);
    if (!in.is_open())
        return;

    string line;
    while (getline(in, line))
    {
        size_t sep = line.find(',');
        if (sep == string::npos)
        {
            continue;
        }
        string name = line.substr(0, sep);
        int score = stoi(line.substr(sep + 1));
        scores[name] = Score(name, score);
    }
    in.close();
}

void ScoreManager::save()
{
    std::ofstream out(filename);
    unordered_map<string, Score>::iterator it;
    for (it = scores.begin(); it != scores.end(); ++it)
    {
        out << it->second.getPlayer() << "," << it->second.getScore() << endl;
    }
    out.close();
}

void ScoreManager::addScore(string name, int score)
{
    unordered_map<string, Score>::iterator it = scores.find(name);
    if (it == scores.end())
    {
        scores[name] = Score(name, score);
    }
    else
    {
        it->second.updateIfHigher(score);
    }
    save();
}
void ScoreManager::printTop(int limit)
{
    vector<Score> sorted;
    unordered_map<string, Score>::iterator it;
    for (it = scores.begin(); it != scores.end(); ++it)
    {
        sorted.push_back(it->second);
    }
    for (size_t i = 0; i < sorted.size(); i++)
    {
        for (size_t j = 0; j < sorted.size() - 1; j++)
        {
            if (sorted[j].getScore() < sorted[j + 1].getScore())
            {
                Score tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
        }
    }
    cout << "===== High Scores =====" << endl;

    int count = limit;
    if (count > (int)sorted.size())
    {
        count = sorted.size();
    }
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << sorted[i].getPlayer() << " - " << sorted[i].getScore() << endl;
    }
    cout << "=======================" << endl;
}