/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** KeyEvent
*/

#include "../include/KeyEvent.hpp"

Arcade::KeyEvent::KeyEvent() :
    Event(Arcade::Event::KEY_EVENT),
    _type(Arcade::KeyEvent::NONE), _key(0)
{
}

Arcade::KeyEvent::KeyEvent(Arcade::KeyEvent::Type event) :
    Event(Arcade::Event::KEY_EVENT),
    _type(event), _key(0)
{
}

Arcade::KeyEvent::KeyEvent(Arcade::KeyEvent::Type event, size_t key) :
    Event(Arcade::Event::KEY_EVENT, key),
    _type(event), _key(key)
{
}

Arcade::KeyEvent::~KeyEvent()
{
}
