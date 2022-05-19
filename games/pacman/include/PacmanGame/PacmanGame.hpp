/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanGame
*/

#ifndef PACMANGAME_HPP_
#define PACMANGAME_HPP_

#include "IGame.hpp"
#include "PacmanMap.hpp"
#include "PacmanComponent.hpp"
#include "PacmanEvent.hpp"
#include "PacmanScore.hpp"
#include <chrono>
#include <queue>

namespace Arcade {
    
    using ICompUPtrVect = std::vector<std::unique_ptr<IComponent>>;
    using IEventUPtr = std::unique_ptr<IEvent>;
    using IEventUPtrVect = std::vector<std::unique_ptr<IEvent>>;
    using IPacCompUPtr = std::unique_ptr<IPacmanComponent>;
    using IPacCompUPtrVect = std::vector<std::unique_ptr<IPacmanComponent>>;

    enum class PacmanGameStatus {
        START,
        IN_GAME,
        GAME_OVER,
        WIN,
        RESET
    };

    class PacmanGame : public IGame {
        public:
            PacmanGame();
            ~PacmanGame();
            void init();
            void stop();
            std::string getGameName() const;
            ICompUPtrVect &getComponents();
            void sendEvents(IEventUPtrVect &events);
            IEvent *getEvent();
            void setPlayerName(std::string const name);
            std::string getPlayerName() const;

        private:
            const std::string _gameName;
            std::unique_ptr<PacmanMap> _map;
            Arcade::IPacCompUPtrVect _components;
            size_t _comptCompt;
            size_t _score;
            size_t _gumsCount;
            std::string _playerName;
            std::queue<PacmanEvent *> _events;
            PacmanEvent *_event = nullptr;
            PacmanGameStatus _status;
            float _gameDelay;
            std::chrono::time_point<std::chrono::high_resolution_clock> _gameClock;
            std::chrono::time_point<std::chrono::high_resolution_clock> _startClock;
            void _initPacman();
            void _initGhosts();
            void _initScore();
            void _handleGame();
            void _handleObjects(IPacCompUPtr &component);
            void _handleTexts(IPacCompUPtr &component);
            void _handleCoreEvents(const IEventUPtr &event);
            void _managePlayerMove(
                const PacmanMap::PlayerMove &move,
                const IPacCompUPtr &pacman
            );
            void _manageEnemiesMove(
                const PacmanMap::PlayerMove &move,
                const IPacCompUPtr &enemy
            );
            void _refreshScore(IPacCompUPtr &component);
            bool _checkDelay();
            void _resetDelay();
            void _gameOver();
            void _win();
            void _start();
            void _reset();
            bool _inGameOrStartCondition();
            bool _gameOverOrWinCondition();
    };
}

#endif /* !PACMANGAME_HPP_ */
