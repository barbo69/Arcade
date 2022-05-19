/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectBigPacGum
*/

#include "ObjectBigPacGum.hpp"

Arcade::ObjectBigPacGum::ObjectBigPacGum(
    const std::size_t &id,
    const PacmanMap::Pos &pos
)
: ComponentObject(id, "./games/pacman/resources/texture/BigPacGum", ComponentObjectType::BIG_PAC_GUM)
{
    Rect rect = { 0, 0, 16, 16  };

    setX(pos.x);
    setY(pos.y);
    setRect(rect);
    setWidth(2);
    setHeight(2);
}

Arcade::ObjectBigPacGum::~ObjectBigPacGum()
{

}
