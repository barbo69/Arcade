/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectLitPacGum
*/

#include "ObjectLitPacGum.hpp"

Arcade::ObjectLitPacGum::ObjectLitPacGum(
    const std::size_t &id,
    const PacmanMap::Pos &pos
)
: ComponentObject(id, "./games/pacman/resources/texture/LitPacGum", ComponentObjectType::LIT_PAC_GUM)
{
    Rect rect = { 0, 0, 16, 16  };

    setX(pos.x);
    setY(pos.y);
    setRect(rect);
    setWidth(1);
    setHeight(1);
}

Arcade::ObjectLitPacGum::~ObjectLitPacGum()
{

}
