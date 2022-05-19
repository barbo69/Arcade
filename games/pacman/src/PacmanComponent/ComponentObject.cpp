/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentObject
*/

#include "ComponentObject.hpp"
#include "ObjectPacman.hpp"
#include "ObjectRedGhost.hpp"
#include "ObjectPinkGhost.hpp"
#include "ObjectBlueGhost.hpp"
#include "ObjectYellowGhost.hpp"
#include "ObjectMap.hpp"
#include "ObjectLitPacGum.hpp"
#include "ObjectBigPacGum.hpp"
#include "PacmanAnim.hpp"
#include "ComponentError.hpp"

#include <iostream>

Arcade::ComponentObject::ComponentObject(
    const std::size_t &id,
    const std::string &file,
    const ComponentObjectType &type
)
: PacmanComponent(id, IComponent::OBJECT, file), _type(type)
{
    _x = 0;
    _y = 0;
    _width = 0;
    _height = 0;
    _rect = { 0, 0, 0, 0 };
}

Arcade::ComponentObject::~ComponentObject()
{

}

Arcade::ComponentObjectType Arcade::ComponentObject::getComponentObjectType() const
{
    return _type;
}

void Arcade::ComponentObject::setX(const size_t x)
{
    _x = x;
}

int Arcade::ComponentObject::getX() const
{
    return _x;
}

void Arcade::ComponentObject::setY(const size_t y)
{
    _y = y; 
} 

int Arcade::ComponentObject::getY() const
{
    return _y;   
}

void Arcade::ComponentObject::setWidth(const int width)
{
    _width = width;
}

int Arcade::ComponentObject::getWidth() const
{
    return _width;   
}

void Arcade::ComponentObject::setHeight(const int height)
{
    _height = height;
}

int Arcade::ComponentObject::getHeight() const
{
    return _height;   
}

void Arcade::ComponentObject::setRect(const Rect rect)
{
    _rect.height = rect.height;
    _rect.width = rect.width;
    _rect.x = rect.x;
    _rect.y = rect.y;
}

Arcade::Rect Arcade::ComponentObject::getRect() const
{
    return _rect;
}

void Arcade::ComponentObject::setObjectAnimation(const PacmanAnimType &type)
{
    _anim = PacmanAnim::makeAnim(type);
}

void Arcade::ComponentObject::setObjectCurrentAnimation(
    const PacmanAnimMove &move
)
{
    _anim->setCurrentAnim(move);
}

void Arcade::ComponentObject::animateObject()
{
    if (_anim != nullptr) {
        _rect = _anim->animate();
    }
}

Arcade::IPacCompUPtr Arcade::ComponentObject::makeObject(
    const std::size_t &id,
    const Arcade::PacmanMap::Pos &pos,
    const ComponentObjectType &type
) 
{
    switch (type) {
        case ComponentObjectType::PACMAN:
            return std::make_unique<ObjectPacman>(id, pos);
        case ComponentObjectType::RED_GHOST:
            return std::make_unique<ObjectRedGhost>(id, pos);
        case ComponentObjectType::PINK_GHOST:
            return std::make_unique<ObjectPinkGhost>(id, pos);
        case ComponentObjectType::BLUE_GHOST:
            return std::make_unique<ObjectBlueGhost>(id, pos);
        case ComponentObjectType::YELLOW_GHOST:
            return std::make_unique<ObjectYellowGhost>(id, pos);
        case ComponentObjectType::MAP:
            return std::make_unique<ObjectMap>(id, pos);
        case ComponentObjectType::LIT_PAC_GUM:
            return std::make_unique<ObjectLitPacGum>(id, pos);
        case ComponentObjectType::BIG_PAC_GUM:
            return std::make_unique<ObjectBigPacGum>(id, pos);
        default:
            throw ComponentError(ComponentErrorType::BAD_USAGE);
    }
}
