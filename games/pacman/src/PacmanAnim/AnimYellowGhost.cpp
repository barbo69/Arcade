/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimYellowGhost
*/

#include "AnimYellowGhost.hpp"

Arcade::AnimYellowGhost::AnimYellowGhost()
{
    _setLeftAnim();
    _setRightAnim();
    _setUpAnim();
    _setDownAnim();
    _setWeaknessAnim();
    _setDeathAnim();
}

Arcade::AnimYellowGhost::~AnimYellowGhost()
{

}

void Arcade::AnimYellowGhost::_setLeftAnim()
{
    RectList list;
    Rect rect = { 16 * 2, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::LEFT);
}

void Arcade::AnimYellowGhost::_setRightAnim()
{
    RectList list;
    Rect rect = { 0, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::RIGHT);
}

void Arcade::AnimYellowGhost::_setDownAnim()
{
    RectList list;
    Rect rect = { 16 * 6, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::DOWN);
}

void Arcade::AnimYellowGhost::_setUpAnim()
{
    RectList list;
    Rect rect = { 16 * 4, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + 16;
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::UP);
}

void Arcade::AnimYellowGhost::_setWeaknessAnim()
{
    RectList list;
    Rect rect = { 16 * 8, 0, 16, 16 };

    list.push_back(rect);
    rect.x = rect.x + (16 * 2);
    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::WEAKNESS);
}

void Arcade::AnimYellowGhost::_setDeathAnim()
{
    RectList list;
    Rect rect = { 16 * 15, 0, 16, 16 };

    list.push_back(rect);
    setAnim(list, 300, PacmanAnimMove::ENEMY_DEATH);
}