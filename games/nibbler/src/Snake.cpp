/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "NibblerGame.hpp"
#include "../../../include/logger.h"

namespace Arcade {

    Snake::Snake(int id, NibblerGame *game):
    NibblerComponent(
        id,
        Type::OBJECT,
        "games/nibbler/resources/snakeHead",
        Rect {.x=0, .y=0, .width=52, .height=52},
        60,
        24,
        NIBBLER_GRID_SIZE,
        NIBBLER_GRID_SIZE
    ), _dir(direction::up), _game(game)
    {
    }

    Snake::~Snake()
    {
    }

    void Snake::_moveTail(int x, int y)
    {
        int oldX, oldY;

        if (_tailParts.size() == 0) {
            return;
        }
        int lastPart = _tailParts[_tailParts.size() - 1];
        _lastPartX = _game->getComponentById(lastPart)->getX();
        _lastPartY = _game->getComponentById(lastPart)->getY();
        for (int id: _tailParts) {
            auto &tailPart = _game->getComponentById(id);
            oldX = tailPart->getX();
            oldY = tailPart->getY();
            tailPart->setX(x);
            tailPart->setY(y);
            x = oldX;
            y = oldY;
        }
    }

    bool Snake::_collideBorders(direction dir)
    {
        switch (dir) {
            case direction::up:
                return _y == 2;
            case direction::down:
                return _y / NIBBLER_GRID_SIZE == NIBBLER_GRID_MAX - 1;
            case direction::left:
                return _x == 2;
            case direction::right:
                return _x / NIBBLER_GRID_SIZE == NIBBLER_GRID_MAX - 1;
            default:
                return false;
        }
    }

    bool Snake::_collide(Snake::direction dir)
    {
        if (_collideBorders(dir))
            return true;
        for (int id: _tailParts) {
            auto &tailPart = _game->getComponentById(id);
            if (tailPart->getX() == _x && tailPart->getY() == _y)
                return true;
        }
        return false;
    }

    void Snake::setNextMove(Snake::direction dir)
    {
        if (dir <= 1 && _dir <= 1) // can't go in opposite direction
            return;
        if (dir > 1 && _dir > 1)
            return;
        _nextDir = dir;
    }

    Snake::direction Snake::getNextMove() const
    {
        return _nextDir;
    }

    void Snake::_lose()
    {
        _lost = true;
    }

    bool Snake::lost() const
    {
        return _lost;
    }

    void Snake::addTail(int id)
    {
        _tailParts.push_back(id);
    }

    void Snake::setX(std::size_t x)
    {
        if (_tailParts.size() == 0) {
            _lastPartX = _x;
            _lastPartY = _y;
        }
        _x = x;
    }

    void Snake::setY(std::size_t y)
    {
        if (_tailParts.size() == 0) {
            _lastPartY = _y;
            _lastPartX = _x;
        }
        _y = y;
    }

    std::size_t Snake::getLastX() const
    {
        return _lastPartX;
    }

    std::size_t Snake::getLastY() const
    {
        return _lastPartY;
    }

    void Snake::operator+=(Snake::direction dir)
    {
        if (this->_collide(dir)) {
            this->_lose();
            return;
        }
        _dir = dir;
        switch (dir)
        {
            case Snake::direction::up:
                this->setY(this->_y - NIBBLER_GRID_SIZE);
                this->_moveTail(_x, _y + NIBBLER_GRID_SIZE);
                break;
            case Snake::direction::down:
                this->setY(this->_y + NIBBLER_GRID_SIZE);
                this->_moveTail(_x, _y - NIBBLER_GRID_SIZE);
                break;
            case Snake::direction::right:
                this->setX(this->_x + NIBBLER_GRID_SIZE);
                this->_moveTail(_x - NIBBLER_GRID_SIZE, _y);
                break;
            case Snake::direction::left:
                this->setX(this->_x - NIBBLER_GRID_SIZE);
                this->_moveTail(_x + NIBBLER_GRID_SIZE, _y);
                break;
            default:
                break;
        }
    }

    using intMap = std::vector<std::vector<int>>;
    intMap Snake::getEmplacement() const
    {
        intMap busySpots(NIBBLER_GRID_MAX, std::vector<int>(NIBBLER_GRID_MAX, 0));

        busySpots[_y / NIBBLER_GRID_SIZE][_x / NIBBLER_GRID_SIZE] = 1;

        for (int id: _tailParts) {
            auto &tailPart = _game->getComponentById(id);
            busySpots[tailPart->getY() / NIBBLER_GRID_SIZE][tailPart->getX() / NIBBLER_GRID_SIZE] = 1;
        }

        return busySpots;
    }

}
