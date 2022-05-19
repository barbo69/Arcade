/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NibblerGame
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

#include <queue>
#include <memory>
#include <string>
#include <vector>
#include <set>

#include "Event.hpp"
#include "NibblerComponent.hpp"
#include "Timer.hpp"
#include "../../../include/IGame.hpp"
#include "../include/ScoreBoard.hpp"

#define NIBBLER_GRID_SIZE 2
#define NIBBLER_GRID_MAX (99 / NIBBLER_GRID_SIZE)

#define NIBBLER_GRID_SIZE 2
#define NIBBLER_GRID_MAX (99 / NIBBLER_GRID_SIZE)

namespace Arcade {
    using intMap = std::vector<std::vector<int>>;
    class NibblerGame: public IGame {
        public:
            class NibblerGameException: public std::exception {
                public:
                    NibblerGameException(std::string msg);
                    ~NibblerGameException();
                    const char *what() const noexcept override;
                private:
                    const std::string _msg;
            };
            NibblerGame();
            ~NibblerGame();
            void init();
            void stop();
            std::string getGameName() const;
            std::vector<std::unique_ptr<IComponent>> &getComponents();
            void sendEvents(std::vector<std::unique_ptr<IEvent>> &events);
            IEvent *getEvent(); // Get event, null if no event
            void setPlayerName(std::string const name);
            std::string getPlayerName() const;
            std::unique_ptr<IComponent> &getComponentById(int id);
        private:
            std::string _name;
            std::chrono::duration<double> _moveInterval;
            std::unique_ptr<Timer> _timer;
            std::vector<std::unique_ptr<IComponent>> _components;
            std::queue<Event *> _events;
            Event *_e = nullptr;
            std::string _playerName = "";
            int _lastId = 0;
            int _appleId;
            int _scoreId;
            size_t _score = 0;
            bool _gameOver = false;
            ScoreBoard _scoreBoard;
            int _playerNameId;
            int _snakeId;

            std::string _font = "games/menu/resources/Gameplay";

            int _generateId();
            void _reset();
            std::unique_ptr<IComponent> &_findTextComponent(std::string text);
            std::unique_ptr<IComponent> &_findComponentByFile(std::string file);
            void _moveApple();
            void _appendTail();
            intMap _getFreeSpots(std::vector<int> & freeY);
            void _incrementScore();
    };
}

#endif /* !IGAME_HPP */
