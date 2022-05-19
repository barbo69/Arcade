/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** ScoreBoard
*/

#ifndef SCOREBOARD_HPP_
#define SCOREBOARD_HPP_

#include <map>
#include <string>

namespace Arcade {

    class ScoreBoard {
        public:
            ScoreBoard();
            ~ScoreBoard();
            void addScore(std::string name, int score);
            std::map<std::string, int> getScores() const;
            void saveScores();
            void loadScores(std::string game);
        protected:
        private:
            std::string _fileName;
            std::map<std::string, int> _scores;
    };

}

#endif /* !SCOREBOARD_HPP_ */
