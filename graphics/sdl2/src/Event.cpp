/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Event
*/

#include "../include/Event.hpp"

Event::Event(std::size_t key):
_key(key)
{}


Event::Event(std::size_t key, int x, int y):
_key(key),
_x(x),
_y(y)
{}

Event::~Event()
{}

std::size_t Event::getKey() const
{
    return _key;
}

void Event::setKey(std::size_t key)
{
    _key = key;
}

Arcade::Pos Event::getMousePos() const
{
    return Arcade::Pos{.x=_x, .y=_y};
}

std::string Event::getData() const
{
    return "";
}

