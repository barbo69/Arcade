/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanComponent
*/

#include "PacmanComponent.hpp"
#include "ComponentError.hpp"
#include "ComponentText.hpp"
#include "ComponentSound.hpp"
#include "ComponentObject.hpp"

Arcade::PacmanComponent::PacmanComponent(
    const std::size_t &id,
    const Type &type,
    const std::string &file
)
: _id(id), _type(type), _file(file)
{
    
}

Arcade::PacmanComponent::~PacmanComponent()
{

}

std::size_t Arcade::PacmanComponent::getId() const
{
    return _id;
}

Arcade::IComponent::Type Arcade::PacmanComponent::getType() const
{
    return _type;
}

Arcade::ComponentObjectType Arcade::PacmanComponent::getComponentObjectType() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

Arcade::ComponentTextType Arcade::PacmanComponent::getComponentTextType() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

std::string Arcade::PacmanComponent::getFile() const
{
    return _file;
}

void Arcade::PacmanComponent::setX(const size_t x)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

int Arcade::PacmanComponent::getX() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setY(const size_t y)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
} 

int Arcade::PacmanComponent::getY() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setWidth(const int width)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

int Arcade::PacmanComponent::getWidth() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setHeight(const int height)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

int Arcade::PacmanComponent::getHeight() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setRect(const Rect rect)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

Arcade::Rect Arcade::PacmanComponent::getRect() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setFontSize(const int size)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

int Arcade::PacmanComponent::getFontSize() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setText(const std::string text)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

std::string Arcade::PacmanComponent::getText() const
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setObjectAnimation(const PacmanAnimType &type)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::setObjectCurrentAnimation(
    const PacmanAnimMove &move
)
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

void Arcade::PacmanComponent::animateObject()
{
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}

Arcade::IPacCompUPtr Arcade::PacmanComponent::makePacmanComponent(
    const std::size_t &id,
    const Type &type,
    const std::string &file
)
{
    switch (type) {
        case IComponent::OBJECT: 
            return std::make_unique<ComponentObject>(id, file, ComponentObjectType::BASIC);
        case IComponent::SOUND: 
            return std::make_unique<ComponentSound>(id, file);
        case IComponent::TEXT: 
            return std::make_unique<ComponentText>(id, file, ComponentTextType::BASIC);
    }
    throw ComponentError(ComponentErrorType::BAD_USAGE);
}
