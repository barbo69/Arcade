/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectMap
*/

#include "ObjectMap.hpp"

Arcade::ObjectMap::ObjectMap(const std::size_t &id, const PacmanMap::Pos &pos)
: ComponentObject(id, "./games/pacman/resources/texture/PacmanMap", ComponentObjectType::MAP)
{
    Rect rect = { 0, 0, 1000, 1000  };

    setX(pos.x);
    setY(pos.y);
    setRect(rect);
    setWidth(100);
    setHeight(100);
}

Arcade::ObjectMap::~ObjectMap()
{
    
}
