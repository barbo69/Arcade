/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Game
*/

#include "Game.hpp"
#include "Component.hpp"
#include "../../../include/keyCodes.hpp"
#include "../include/Event.hpp"
#include <filesystem>
#include <set>
#include <regex>
#include <iostream>
#include "../../../include/logger.h"

namespace Arcade
{
    Game::Game(std::string name):
    _name(name)
    {}

    Game::~Game()
    {}

    void Game::_createMenu()
    {
        Rect rect{.x=0, .y=0, .width=100, .height=100};
        _components.push_back(std::make_unique<Component>(_generateId(), "Menu", std::filesystem::absolute(_font), rect, 43, 10, 15, 7, 10));
        _components.push_back(std::make_unique<Component>(_generateId(), "Libraries", std::filesystem::absolute(_font), rect, _libs_x - 5, _libs_y, 18, 5, 10));
        _components.push_back(std::make_unique<Component>(_generateId(), "Games", std::filesystem::absolute(_font), rect, _games_x - 2, _games_y, 13, 5, 10));
        rect.width = 200;
        _components.push_back(std::make_unique<Component>(_generateId(), COPYRIGHT_1, std::filesystem::absolute(_font), rect, 40, 87, 20, 2, 8));
        _components.push_back(std::make_unique<Component>(_generateId(), COPYRIGHT_2, std::filesystem::absolute(_font), rect, 30, 90, 40, 2, 8));
        _components.push_back(std::make_unique<Component>(_generateId(), COPYRIGHT_3, std::filesystem::absolute(_font), rect, 40, 93, 20, 2, 8));
        _games_y += 10;
        _libs_y += 10;
    }

    void Game::_listLibraries()
    {
        std::filesystem::path libsdir = "./lib";
        std::regex libraryName("arcade_(\\S+)\\.so");
        std::smatch m;

        for (const auto &it: std::filesystem::directory_iterator(std::filesystem::absolute(libsdir))) {
            std::string pathAsString = it.path();
            if (std::regex_search(pathAsString, m, libraryName)) {
                if (_validGraphicLibraries.contains(m[1])) {
                    Rect rect{.x=0, .y=0, .width=100, .height=100};
                    _availableGraphicLibraries.emplace(m[1]);
                    _components.push_back(std::make_unique<Component>(_generateId(), m[1], std::filesystem::absolute(_font), rect, _libs_x, _libs_y, 8, 3, 10));
                    _libs_y+= 12;
                } else {
                    Rect rect{.x=0, .y=0, .width=100, .height=100};
                    _availableGames.emplace(m[1]);
                    _components.push_back(std::make_unique<Component>(_generateId(), m[1], std::filesystem::absolute(_font), rect, _games_x, _games_y, 8, 3, 10));
                    _games_y += 12;
                }
            }
        }
        _selectedDisplay = _availableGraphicLibraries.begin();
        _selectedGame = _availableGames.begin();
    }

    std::unique_ptr<IComponent> &Game::_findTextComponent(std::string text)
    {
        for (auto &it: _components) {
            if (it->getType() == Arcade::IComponent::TEXT && it->getText() == text) {
                return it;
            }
        }
        return *_components.end();
    }

    std::unique_ptr<IComponent> &Game::_findComponentByFile(std::string file)
    {
        auto filepath = std::filesystem::absolute("games/menu/resources/" + file);

        for (auto &it: _components) {
            if (it->getFile() == filepath) {
                return it;
            }
        }
        return *_components.end();
    }

    void Game::_reset()
    {
        _games_y = 30;
        _libs_y = _games_y;
        _games_x = 70;
        _libs_x = 20;
        _components.clear();
        _playerName = "";
        _lastId = 0;
    }

    void Game::_initGhosts()
    {
        int ghost_w = 3, ghost_h = 3;
        Rect rect {.x=0, .y=0, .width=1024, .height=1024};

        auto &firstDisplay = _findTextComponent(*_availableGraphicLibraries.begin());

        _components.push_back(std::make_unique<Component>(
            _generateId(),
            Arcade::IComponent::OBJECT, std::filesystem::absolute("games/menu/resources/ghost"),
            rect,
            firstDisplay->getX() - 4,
            firstDisplay->getY(),
            ghost_w,
            ghost_h
        ));

        auto &firstGame = _findTextComponent(*_availableGames.begin());
        Rect rect2 {.x=0, .y=0, .width=650, .height=650};
        firstGame->getX();
        _components.push_back(std::make_unique<Component>(
            _generateId(),
            Arcade::IComponent::OBJECT, std::filesystem::absolute("games/menu/resources/ghost2"),
            rect2,
            firstGame->getX() - 4,
            firstGame->getY(),
            ghost_w,
            ghost_h
        ));
    }

    void Game::_initPlayerName()
    {
        Rect rect{.x=0, .y=0, .width=100, .height=100};
        _components.push_back(std::make_unique<Component>(_generateId(), "Player: " + _playerName , std::filesystem::absolute(_font), rect, _libs_x, 75, 8, 3, 10));
    }

    void Game::init()
    {
        _createMenu();
        _listLibraries();
        _initGhosts();
        _initPlayerName();
    }

    void Game::_moveGhost(char which)
    {
        if (which == 1) {
            auto &ghost = _findComponentByFile("ghost");
            _selectedDisplay++;
            if (_selectedDisplay == _availableGraphicLibraries.end())
                _selectedDisplay = _availableGraphicLibraries.begin();
            auto &display = _findTextComponent(*_selectedDisplay);
            ghost->setY(display->getY());
            ghost->setX(display->getX() - 4);
        } else {
            auto &ghost = _findComponentByFile("ghost2");
            _selectedGame++;
            if (_selectedGame == _availableGames.end())
                _selectedGame = _availableGames.begin();
            auto &display = _findTextComponent(*_selectedGame);
            ghost->setY(display->getY());
            ghost->setX(display->getX() - 4);
        }

    }

    void Game::stop()
    {
        _reset();
    }

    std::string Game::getGameName() const
    {
        return _name;
    }

    std::vector<std::unique_ptr<IComponent>> &Game::getComponents()
    {
        return _components;
    }

    bool Game::_isText(std::size_t val)
    {
        return ((val + 97 <= 'z' && val + 97 >= 'a') || val == Keycodes::SPACE);
    }


    void Game::_inputPlayerName(int val)
    {
        if (_playerName.length() >= _max_name_len)
            return;
        val = val == Keycodes::SPACE ? ' ' : val + 97;
        auto &nameComponent = _findTextComponent("Player: " + _playerName);
        _playerName += val;
        nameComponent->setWidth(nameComponent->getWidth() + 2);
        nameComponent->setText("Player: " + _playerName);
    }

    void Game::sendEvents(std::vector<std::unique_ptr<IEvent>> &events)
    {
        for (auto &e: events) {
            int val = e->getKey();
            if (_isText(val)) {
                _inputPlayerName(val);
                break;
            }
            switch (e->getKey()) {
                case Keycodes::ESC:
                    _events.push(new Event('q'));
                    break;
                case Keycodes::ENTER:
                    _events.push(new Event('r', *_selectedDisplay));
                    _events.push(new Event('r', *_selectedGame));
                    break;
                // case 'p' - 97:
                //     _events.push(new Event('p'));
                //     break;
                // case 'm' - 97:
                //     _events.push(new Event('m'));
                //     break;
                // case 'l' - 97:
                //     _events.push(new Event('l'));
                //     break;
                case Keycodes::ARROW_DOWN:
                    _moveGhost(1);
                    break;
                case  Keycodes::ARROW_RIGHT:
                    _moveGhost(2);
                    break;
                default:
                    break;
            }
        }
    }
    IEvent *Game::getEvent()
    {
        if (_e)
            delete _e;
        if (!_events.empty()) {
            _e = _events.front();
            _events.pop();
        } else {
            _e = nullptr;
        }
        return _e;
    };

    int Game::_generateId()
    {
        _lastId++;
        return _lastId - 1;
    }

    int getComponentPos(std::vector<std::unique_ptr<IComponent>> &components, int id)
    {
        int i = 0;

        for (auto &it: components) {
            if (it->getId() == id)
                return i;
            i++;
        }
        return -1;
    }

    void Game::setPlayerName(std::string const playerName)
    {
        _playerName = playerName;
    }

    std::string Game::getPlayerName() const
    {
        return _playerName;
    }

} // namespace Arcade
