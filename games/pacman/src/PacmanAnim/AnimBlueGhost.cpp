/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimBlueGhost
*/

#include "AnimBlueGhost.hpp"

Arcade::AnimBlueGhost::AnimBlueGhost()
{
    _setLeftAnim();
    _setRightAnim();
    _setUpAnim();
    _setDownAnim();
    _setWeaknessAnim();
    _setDeathAnim();
}

Arcade::AnimBlueGhost::~AnimBlueGhost()
{
    
}

void Arcade::AnimBlueGhost::_setLeftAnim()
{
    RectList list;
    Rect rect = { 16 * 2, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::LEFT);
}

void Arcade::AnimBlueGhost::_setRightAnim()
{
    RectList list;
    Rect rect = { 0, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::RIGHT);
}

void Arcade::AnimBlueGhost::_setDownAnim()
{
    RectList list;
    Rect rect = { 16 * 6, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::DOWN);
}

void Arcade::AnimBlueGhost::_setUpAnim()
{
    RectList list;
    Rect rect = { 16 * 4, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::UP);
}

void Arcade::AnimBlueGhost::_setWeaknessAnim()
{
    RectList list;
    Rect rect = { 16 * 8, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + (16 * 2);
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::WEAKNESS);
}

void Arcade::AnimBlueGhost::_setDeathAnim()
{
    RectList list;
    Rect rect = { 16 * 15, 0, 16, 16 };

    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::ENEMY_DEATH);
}