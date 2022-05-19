/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanEvent
*/

#include "PacmanEvent.hpp"

Arcade::PacmanEvent::PacmanEvent(const std::size_t key)
{
    _mouse = { 0, 0 };
    _key = key;
    _data = "";
}

Arcade::PacmanEvent::PacmanEvent(const std::size_t &key, const std::string &data)
{
    _mouse = { 0, 0 };
    _key = key;
    _data = data;
}

Arcade::PacmanEvent::~PacmanEvent()
{

}

std::size_t Arcade::PacmanEvent::getKey() const
{
    return _key;
}

void Arcade::PacmanEvent::setKey(std::size_t const key)
{
    _key = key;
}

Arcade::Pos Arcade::PacmanEvent::getMousePos() const
{
    return _mouse;
}

std::string Arcade::PacmanEvent::getData() const
{
    return _data;
}

