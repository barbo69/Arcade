/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimPacman
*/

#include "AnimPacman.hpp"

Arcade::AnimPacman::AnimPacman()
{
    _setLeftAnim();
    _setRightAnim();
    _setUpAnim();
    _setDownAnim();
    _setDeathAnim();
}

Arcade::AnimPacman::~AnimPacman()
{
    
}

void Arcade::AnimPacman::_setLeftAnim()
{
    RectList list;
    Rect rect = { 0, 16, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 150, PacmanAnimMove::LEFT);
}

void Arcade::AnimPacman::_setRightAnim()
{
    RectList list;
    Rect rect = { 0, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 150, PacmanAnimMove::RIGHT);
}

void Arcade::AnimPacman::_setDownAnim()
{
    RectList list;
    Rect rect = { 0, 16 * 3, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 150, PacmanAnimMove::DOWN);
}

void Arcade::AnimPacman::_setUpAnim()
{
    RectList list;
    Rect rect = { 0, 16 * 2, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 150, PacmanAnimMove::UP);
}

void Arcade::AnimPacman::_setDeathAnim()
{
    RectList list;
    Rect rect = { 16 * 2, 0, 16, 16 };

    list.push_back(rect);
    for (int i = 0; i < 13; i++) {
        rect.x = rect.x + 16;
        list.push_back(rect);    
    }
    setAnim(list, 150, PacmanAnimMove::DEATH);
}

