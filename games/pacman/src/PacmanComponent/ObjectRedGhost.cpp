/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectRedGhost
*/

#include "ObjectRedGhost.hpp"

Arcade::ObjectRedGhost::ObjectRedGhost(const std::size_t &id, const PacmanMap::Pos &pos)
: ComponentObject(id, "./games/pacman/resources/texture/RedGhostSprites", ComponentObjectType::RED_GHOST)
{
    Rect rect = { 0, 0, 16, 16 };

    setX(pos.x);
    setY(pos.y);
    setRect(rect);
    setWidth(3);
    setHeight(3);
    setObjectAnimation(PacmanAnimType::RED_GHOST);
}

Arcade::ObjectRedGhost::~ObjectRedGhost()
{
    
}
