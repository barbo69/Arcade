/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponentObject
*/

#include "SfmlComponentObject.hpp"
#include <iostream>

Arcade::SfmlComponentObject::SfmlComponentObject(
    const size_t &id,
    const std::unique_ptr<ISfmlData> &data
)
: SfmlComponent(id, IComponent::OBJECT, data)
{
    sf::IntRect textureRect = { 0, 0, 0, 0 };

    if (data->getType() != SfmlDataType::TEXTURE)
        throw std::runtime_error("Wrong data type");
    _sprite.setTexture(data->getTexture());
    _scale = _sprite.getScale();
    textureRect = _sprite.getTextureRect();
    _width = textureRect.width;
    _height = textureRect.height;
}

Arcade::SfmlComponentObject::~SfmlComponentObject()
{
       
}

void Arcade::SfmlComponentObject::setPos(const int x, const int y)
{
    sf::Vector2f pos = { static_cast<float>(x), static_cast<float>(y) };

    _sprite.setPosition(pos);
}

sf::Vector2f Arcade::SfmlComponentObject::getPos() const
{
    return _sprite.getPosition();
}

void Arcade::SfmlComponentObject::setRect(const Rect rect)
{
    sf::IntRect intRect;

    intRect.height = rect.height;
    intRect.width = rect.width;
    intRect.left = rect.x;
    intRect.top = rect.y;
    _sprite.setTextureRect(intRect);
    _width = intRect.width;
    _height = intRect.height;
}

sf::IntRect Arcade::SfmlComponentObject::getRect() const
{
    return _sprite.getTextureRect();
}

void Arcade::SfmlComponentObject::setWidth(const int width)
{
    float pixelNb = _width / (GRID_PIXEL_SIZE);
    float scale = width / pixelNb;

    _scale.x = scale;
    _sprite.setScale(_scale);
}

int Arcade::SfmlComponentObject::getWidth() const
{
    return _width;
}

void Arcade::SfmlComponentObject::setHeight(const int height)
{
    float pixelNb = _height / (GRID_PIXEL_SIZE);
    float scale = height / pixelNb;

    _scale.y = scale;
    _sprite.setScale(_scale);
}

int Arcade::SfmlComponentObject::getHeight() const
{
    return _height;
}


void Arcade::SfmlComponentObject::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}