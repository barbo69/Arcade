/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponent
*/

#include "SfmlComponent.hpp"
#include "SfmlComponentObject.hpp"
#include "SfmlComponentSound.hpp"
#include "SfmlComponentText.hpp"

Arcade::SfmlComponent::SfmlComponent(
    const size_t &id,
    const IComponent::Type &type,
    const std::unique_ptr<ISfmlData> &data

)
: _id(id), _type(type), _data(data)
{

}

Arcade::SfmlComponent::~SfmlComponent()
{
    
}

std::size_t Arcade::SfmlComponent::getId() const
{
    return _id;
}

Arcade::IComponent::Type Arcade::SfmlComponent::getType() const
{
    return _type;
}

std::string Arcade::SfmlComponent::getFile() const
{
    return _data->getPath();
}

void Arcade::SfmlComponent::setPos(const int x, const int y)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

sf::Vector2f Arcade::SfmlComponent::getPos() const
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::setRect(const Rect rect)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

sf::IntRect Arcade::SfmlComponent::getRect() const
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::setWidth(const int width)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

int Arcade::SfmlComponent::getWidth() const
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::setHeight(const int height)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

int Arcade::SfmlComponent::getHeight() const
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::setFontSize(const int fontSize)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

int Arcade::SfmlComponent::getFontSize() const
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::setText(const std::string &text)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

std::string Arcade::SfmlComponent::getText() const
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::draw(sf::RenderWindow &window)
{
    throw std::runtime_error("Bad usage of SfmlComponent");
}

void Arcade::SfmlComponent::setUse(bool use)
{
    _use = use;
}

bool Arcade::SfmlComponent::isUsed() const
{
    return _use;
}


std::unique_ptr<Arcade::ISfmlComponent> Arcade::SfmlComponent::sfmlComponentFactory(
    const size_t &id,
    const Arcade::IComponent::Type &type,
    const std::unique_ptr<ISfmlData> &data

)
{
    switch (type) {
        case Arcade::IComponent::Type::OBJECT:
            return std::make_unique<SfmlComponentObject>(id, data);
        case Arcade::IComponent::Type::SOUND:
            return std::make_unique<SfmlComponentSound>(id, data);
        case Arcade::IComponent::Type::TEXT:
            return std::make_unique<SfmlComponentText>(id, data);
    }
    throw std::runtime_error("Bad usage of SfmlComponent");
}