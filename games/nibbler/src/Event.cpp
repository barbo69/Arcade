/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Event
*/

#include "Event.hpp"

Event::Event(std::size_t key):
_key(key)
{}


Event::Event(std::size_t key, std::string data):
_key(key), _data(data)
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
    return Arcade::Pos {.x=0, .y=0};
}

std::string Event::getData() const
{
    return _data;
}

