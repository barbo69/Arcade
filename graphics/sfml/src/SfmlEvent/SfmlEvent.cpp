/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlEvent
*/

#include "SfmlEvent.hpp"
#include <stdexcept>
#include <iostream>

Arcade::SfmlEvent::SfmlEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    sf::Mouse mouse;
    sf::Vector2i mousePos { 0, 0 };

    _key = static_cast<size_t>(event.key.code);
    _mousePos = { -1, -1 };
    mousePos = mouse.getPosition(window);
    _mousePos = { mousePos.x, _mousePos.y };
}

Arcade::SfmlEvent::~SfmlEvent()
{
}

std::size_t Arcade::SfmlEvent::getKey() const
{
    return _key;
}

void Arcade::SfmlEvent::setKey(std::size_t const key)
{
    _key = key;
}

Arcade::Pos Arcade::SfmlEvent::getMousePos() const
{
    return _mousePos;
}

std::string Arcade::SfmlEvent::getData() const
{
    return "";
}
