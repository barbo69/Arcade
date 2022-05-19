/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Event
*/

#include "../include/Event.hpp"

Arcade::Event::Event() :
    _type(Arcade::Event::NONE), _key(0), _pos({0, 0})
{
}

Arcade::Event::Event(Arcade::Event::Type event) :
    _type(event), _key(0), _pos({0, 0})
{
}

Arcade::Event::Event(Arcade::Event::Type event, size_t key) :
    _type(event), _key(key), _pos({0, 0})
{
}

Arcade::Event::Event(Arcade::Event::Type event, Arcade::Pos pos) :
    _type(event), _key(0), _pos(pos)
{
}

Arcade::Event::Event(Arcade::Event::Type event, size_t key, Arcade::Pos pos) :
    _type(event), _key(key), _pos(pos)
{
}

Arcade::Event::~Event()
{
}

std::size_t Arcade::Event::getKey() const
{
    return _key;
}

void Arcade::Event::setKey(std::size_t const key)
{
    _key = key;
}

Arcade::Pos Arcade::Event::getMousePos() const
{
    return _pos;
}
