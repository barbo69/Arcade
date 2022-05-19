/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanScore
*/

#include "PacmanScore.hpp"
#include <fstream>
#include <regex>
#include <iostream>

Arcade::PacmanScore::PacmanScore()
{

}

Arcade::PacmanScore::~PacmanScore()
{

}

void Arcade::PacmanScore::addScore(std::string name, int score)
{
    if (name.length() == 0)
            return;
    if (_scores.find(name) != _scores.end()) {
        if (_scores[name] < score) {
            _scores[name] = score;
        }
    } else {
        _scores[name] = score;
    }
}

std::map<std::string, int> Arcade::PacmanScore::getScores() const
{
    return _scores;
}

int Arcade::PacmanScore::getScore(const std::string name) const
{
    std::map<std::string, int>::const_iterator it = _scores.find(name);

    if (it != _scores.end())
        return it->second;
    return 0;
}

void Arcade::PacmanScore::saveScores()
{
    std::ofstream file(_fileName);

    if (!file.is_open())
        return;
    for (auto &score : _scores)
        file << score.first << "=" << score.second << std::endl;
    file.close();
}

void Arcade::PacmanScore::loadScores(std::string game)
{
    std::ifstream file(game + ".score");

    _fileName = game + ".score";
    if (!file.is_open())
        return;
    std::string line;
    std::regex reg("([a-z ]+)=([0-9]+)");
    std::smatch match;
    while (std::getline(file, line)) {
        if (std::regex_match(line, match, reg))
            _scores[match[1]] = std::stoi(match[2]);
    }
    file.close();
}