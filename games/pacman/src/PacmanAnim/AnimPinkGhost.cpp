/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimPinkGhost
*/

#include "AnimPinkGhost.hpp"

Arcade::AnimPinkGhost::AnimPinkGhost()
{
    _setLeftAnim();
    _setRightAnim();
    _setUpAnim();
    _setDownAnim();
    _setWeaknessAnim();
    _setDeathAnim();
}

Arcade::AnimPinkGhost::~AnimPinkGhost()
{
    
}

void Arcade::AnimPinkGhost::_setLeftAnim()
{
    RectList list;
    Rect rect = { 16 * 2, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::LEFT);
}

void Arcade::AnimPinkGhost::_setRightAnim()
{
    RectList list;
    Rect rect = { 0, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::RIGHT);
}

void Arcade::AnimPinkGhost::_setDownAnim()
{
    RectList list;
    Rect rect = { 16 * 6, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::DOWN);
}

void Arcade::AnimPinkGhost::_setUpAnim()
{
    RectList list;
    Rect rect = { 16 * 4, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::UP);
}

void Arcade::AnimPinkGhost::_setWeaknessAnim()
{
    RectList list;
    Rect rect = { 16 * 8, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + (16 * 2);
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::WEAKNESS);
}

void Arcade::AnimPinkGhost::_setDeathAnim()
{
    RectList list;
    Rect rect = { 16 * 15, 0, 16, 16 };

    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::ENEMY_DEATH);
}