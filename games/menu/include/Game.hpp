/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

#include <queue>
#include <memory>
#include <string>
#include <set>

#include "Event.hpp"
#include "../../../include/IGame.hpp"

#define COPYRIGHT_1 "Tupac-Man"
#define COPYRIGHT_2 "Barbo Franco Momos"
#define COPYRIGHT_3 "2020-2025"

namespace Arcade {
    class Game: public IGame {
        public:
            Game(std::string name);
            ~Game();
            void init();
            void stop();
            std::string getGameName() const;
            std::vector<std::unique_ptr<IComponent>> &getComponents();
            void sendEvents(std::vector<std::unique_ptr<IEvent>> &events);
            IEvent *getEvent(); // Get event, null if no event
            void setPlayerName(std::string const name);
            std::string getPlayerName() const;
        private:
            std::string _name;
            std::vector<std::unique_ptr<IComponent>> _components;
            std::set<std::string> _validGraphicLibraries {"sdl2", "ncurses", "sfml"};
            std::set<std::string> _availableGames;
            std::set<std::string> _availableGraphicLibraries;
            std::queue<Event *> _events;
            std::set<std::string>::iterator _selectedGame;
            std::set<std::string>::iterator _selectedDisplay;
            Event *_e = nullptr;
            std::string _playerName = "";

            std::string _font = "games/menu/resources/Gameplay";
            int _games_y = 30;
            int _libs_y = _games_y;
            int _games_x = 70;
            int _libs_x = 20;
            unsigned int _max_name_len = 13;
            int _lastId = 0;

            int _generateId();
            void _createMenu();
            void _listLibraries();
            void _reset();
            void _initGhosts();
            void _moveGhost(char which);
            std::unique_ptr<IComponent> &_findTextComponent(std::string text);
            std::unique_ptr<IComponent> &_findComponentByFile(std::string file);
            void _inputPlayerName(int val);
            bool _isText(std::size_t val);
            void _initPlayerName();

    };
}

#endif /* !IGAME_HPP */
