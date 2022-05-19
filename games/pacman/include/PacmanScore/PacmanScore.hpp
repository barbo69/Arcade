/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanScore
*/

#ifndef PACMANSCORE_HPP_
#define PACMANSCORE_HPP_

#include <map>
#include <string>

namespace Arcade {
    class PacmanScore {
        public:
            PacmanScore();
            ~PacmanScore();
            void addScore(std::string name, int score);
            std::map<std::string, int> getScores() const;
            int getScore(const std::string name) const;
            void saveScores();
            void loadScores(std::string game);

        private:
            std::string _fileName;
            std::map<std::string, int> _scores;
    };
}

#endif /* !PACMANSCORE_HPP_ */
