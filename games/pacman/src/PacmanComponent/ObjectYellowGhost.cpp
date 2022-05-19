/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectYellowGhost
*/

#include "ObjectYellowGhost.hpp"

Arcade::ObjectYellowGhost::ObjectYellowGhost(const std::size_t &id, const PacmanMap::Pos &pos)
: ComponentObject(id, "./games/pacman/resources/texture/YellowGhostSprites", ComponentObjectType::YELLOW_GHOST)
{
    Rect rect = { 0, 0, 16, 16 };

    setX(pos.x);
    setY(pos.y);
    setRect(rect);
    setWidth(3);
    setHeight(3);
    setObjectAnimation(PacmanAnimType::YELLOW_GHOST);
}

Arcade::ObjectYellowGhost::~ObjectYellowGhost()
{
    
}
