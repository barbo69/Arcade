/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** snakeComponent
*/

#ifndef SNAKECOMPONENT_HPP_
#define SNAKECOMPONENT_HPP_

#include <string>
#include <vector>
#include <memory>
#include "NibblerComponent.hpp"
#include "NibblerGame.hpp"
#include <chrono>

namespace Arcade {

    using intMap = std::vector<std::vector<int>>;

    class Snake: public NibblerComponent {
        public:

            enum direction {
                up,
                down,
                left,
                right
            };

            Snake(int id, NibblerGame *game);
            ~Snake();
            void setX(std::size_t x) override;
            void setY(std::size_t y) override;
            std::size_t getLastX() const;
            std::size_t getLastY() const;
            void addTail(int id);
            void operator+=(Snake::direction dir);
            void setNextMove(Snake::direction dir);
            direction getNextMove() const;
            intMap getEmplacement() const;
            bool lost() const;
        private:
            direction _nextDir = right;
            direction _dir = right;
            NibblerGame *_game;
            std::vector<int> _tailParts;
            std::size_t _lastPartX;
            std::size_t _lastPartY;
            bool _lost = false;

            bool _collide(direction dir);
            bool _collideBorders(direction dir);
            void _lose();
            void _moveTail(int x, int y);
    };
}

#endif /* !SNAKECOMPONENT_HPP_ */
