/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** NibblerGame
*/

#include "NibblerGame.hpp"
#include "Snake.hpp"
#include "../../../include/keyCodes.hpp"
#include "../include/Event.hpp"
#include <filesystem>
#include <set>
#include <regex>
#include <iostream>

namespace Arcade
{

    NibblerGame::NibblerGameException::NibblerGameException(std::string msg):
    _msg(msg)
    {}

    NibblerGame::NibblerGameException::~NibblerGameException()
    {}

    const char *NibblerGame::NibblerGameException::what() const noexcept
    {
        return _msg.data();
    }

    NibblerGame::NibblerGame():
    _name("nibbler"), _moveInterval(0.15), _timer(std::make_unique<Timer>())
    {
        _timer->start();
    }

    NibblerGame::~NibblerGame()
    {}

    std::unique_ptr<IComponent> &NibblerGame::_findTextComponent(std::string text)
    {
        for (auto &it: _components) {
            if (it->getType() == Arcade::IComponent::TEXT && it->getText() == text) {
                return it;
            }
        }
        return *_components.end();
    }

    std::unique_ptr<IComponent> &NibblerGame::_findComponentByFile(std::string file)
    {
        auto filepath = std::filesystem::absolute("games/nibbler/resources/" + file);

        for (auto &it: _components) {
            if (it->getFile() == filepath) {
                return it;
            }
        }
        return *_components.end();
    }

    void NibblerGame::_reset()
    {
        _components.clear();
        _lastId = 0;
        _timer->reset();
        _score = 0;
    }

    void NibblerGame::init()
    {
        _snakeId = _generateId();
        _appleId = _generateId();
        _scoreId = _generateId();
        _playerNameId = _generateId();
        _components.push_back(std::make_unique<Snake>(_snakeId, this));

        Rect r = {0, 0, 52, 52};
        _components.push_back(std::make_unique<NibblerComponent>(_appleId, IComponent::OBJECT, "games/nibbler/resources/apple", r, 0, 0, NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE));
        r.height = 100;
        r.width = 100;
        _components.push_back(std::make_unique<NibblerComponent>(_generateId(), "player", "games/nibbler/resources/Gameplay", r, -40, 35, 20, 3, 10));
        _components.push_back(std::make_unique<NibblerComponent>(_playerNameId, _playerName, "games/nibbler/resources/Gameplay", r, -40, 40, 20, 3, 10));
        _components.push_back(std::make_unique<NibblerComponent>(_generateId(), "score", "games/nibbler/resources/Gameplay", r, -40, 50, 20, 3, 10));
        _components.push_back(std::make_unique<NibblerComponent>(_scoreId, "0", "games/nibbler/resources/Gameplay", r, -40, 55, 3, 3, 10));
        _moveApple();
        _scoreBoard.loadScores(_name);
        //  place walls around the map
        for (int i = 0; i < 50; i++) {
            _components.push_back(std::make_unique<NibblerComponent>(_generateId(), IComponent::OBJECT, "games/nibbler/resources/wall", Rect {0, 0, 52, 52}, i * NIBBLER_GRID_SIZE, 0, NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE));
            _components.push_back(std::make_unique<NibblerComponent>(_generateId(), IComponent::OBJECT, "games/nibbler/resources/wall", Rect {0, 0, 52, 52}, i * NIBBLER_GRID_SIZE, 98, NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE));
            _components.push_back(std::make_unique<NibblerComponent>(_generateId(), IComponent::OBJECT, "games/nibbler/resources/wall", Rect {0, 0, 52, 52}, 0, i * NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE));
            _components.push_back(std::make_unique<NibblerComponent>(_generateId(), IComponent::OBJECT, "games/nibbler/resources/wall", Rect {0, 0, 52, 52}, 98, i * NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE));
        }
    }

    void NibblerGame::stop()
    {
        _scoreBoard.saveScores();
        _reset();
    }

    std::string NibblerGame::getGameName() const
    {
        return _name;
    }

    std::vector<std::unique_ptr<IComponent>> &NibblerGame::getComponents()
    {
        return _components;
    }

    std::unique_ptr<IComponent> &NibblerGame::getComponentById(int id)
    {
        for (auto &it: _components) {
            if (it->getId() == id) {
                return it;
            }
        }
        throw NibblerGameException("Couln't find id");
    }


    void NibblerGame::sendEvents(std::vector<std::unique_ptr<IEvent>> &events)
    {
        auto &snake = reinterpret_cast<std::unique_ptr<Snake> &>(this->getComponentById(_snakeId));
        for (auto &e: events) {
            int val = e->getKey();
            switch (e->getKey()) {
                case Keycodes::ESC:
                    _events.push(new Event('q'));
                    break;
                case 'n' - 97:
                    _events.push(new Event('n'));
                    break;
                case 'p' - 97:
                    _events.push(new Event('p'));
                    break;
                case 'm' - 97:
                    _events.push(new Event('m'));
                    break;
                case 'l' - 97:
                    _events.push(new Event('l'));
                    break;
                case 's' - 97:
                    _events.push(new Event('s'));
                    break;
                case Keycodes::ARROW_DOWN:
                    snake->setNextMove(Snake::direction::down);
                    break;
                case  Keycodes::ARROW_RIGHT:
                    snake->setNextMove(Snake::direction::right);
                    break;
                case  Keycodes::ARROW_UP:
                    snake->setNextMove(Snake::direction::up);
                    break;
                case  Keycodes::ARROW_LEFT:
                    snake->setNextMove(Snake::direction::left);
                    break;
                default:
                    break;
            }
        }
        if (_gameOver || _timer->getElapsedTime() < _moveInterval)
            return;
        *snake += snake->getNextMove();
        if (snake->lost()) {
            _gameOver = true;
            _components.push_back(std::make_unique<NibblerComponent>(_generateId(), "game over", "games/nibbler/resources/Gameplay", Rect{0, 0, 100, 100}, 40, 30, 20, 3, 15));
            _scoreBoard.saveScores();
            return;
        }
        auto &apple = reinterpret_cast<std::unique_ptr<NibblerComponent> &>(this->getComponentById(_appleId));
        if (snake->getX() == apple->getX() && snake->getY() == apple->getY()) {
            _appendTail();
            _moveApple();
            _incrementScore();
        }
        _timer->reset();
    }

    void NibblerGame::_incrementScore()
    {
        _score += 10;
        auto &score = reinterpret_cast<std::unique_ptr<NibblerComponent> &>(this->getComponentById(_scoreId));
        score->setText(std::to_string(_score));
        score->setWidth(std::to_string(_score).size() * 4);
        _scoreBoard.addScore(_playerName, _score);
    }

    intMap NibblerGame::_getFreeSpots(std::vector<int> &freeY)
    {
        auto &snake = reinterpret_cast<std::unique_ptr<Snake> &>(this->getComponentById(_snakeId));
        intMap map = snake->getEmplacement();

        intMap freeSpots;
        for (int i = 1; i < map.size() - 1; i++) {
            if (map[i].size() != 0) {
                freeY.push_back(i);
            }
        }
        for (auto it: freeY) {
            freeSpots.push_back(std::vector<int>());
            for (int i = 1; i < map[it].size() - 1; i++) {
                if (map[it][i] == 0) {
                    freeSpots[it - 1].push_back(i);
                }
            }
        }
        return freeSpots;
    }

    void NibblerGame::_moveApple()
    {
        std::vector<int> freeY;
        intMap freeSpots = _getFreeSpots(freeY);

        if (freeY.size() == 0) {
            // return _win()
        }
        int randY = freeY[rand() % freeY.size()];
        int randX = freeSpots[randY][rand() % freeSpots[randY].size()];
        auto &apple = reinterpret_cast<std::unique_ptr<NibblerComponent> &>(this->getComponentById(_appleId));
        apple->setX(randX * NIBBLER_GRID_SIZE);
        apple->setY(randY * NIBBLER_GRID_SIZE);
    }

    IEvent *NibblerGame::getEvent()
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

    int NibblerGame::_generateId()
    {
        static int current = 0;

        current++;
        return current - 1;
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

    void NibblerGame::setPlayerName(std::string const playerName)
    {
        _playerName = playerName;
        auto &player = reinterpret_cast<std::unique_ptr<NibblerComponent> &>(this->getComponentById(_playerNameId));
        player->setText(playerName);
    }

    std::string NibblerGame::getPlayerName() const
    {
        return _playerName;
    }
    void NibblerGame::_appendTail()
    {
        auto &snake = reinterpret_cast<std::unique_ptr<Snake> &>(this->getComponentById(_snakeId));
        int tailId = _generateId();
        Rect r = {.x=0, .y=0, .width=52, .height=52};
        snake->addTail(tailId);
        _components.push_back(std::make_unique<NibblerComponent>(tailId, IComponent::OBJECT, "games/nibbler/resources/snakeHead", r, snake->getLastX(), snake->getLastY(), NIBBLER_GRID_SIZE, NIBBLER_GRID_SIZE));
    }

} // namespace Arcade
