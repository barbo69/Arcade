/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MouseEvent
*/

#include "../include/MouseEvent.hpp"

Arcade::MouseEvent::MouseEvent() :
    Event(Arcade::Event::Type::MOUSE_EVENT),
    _type(Arcade::MouseEvent::NONE), _pos({0, 0})
{
}

Arcade::MouseEvent::MouseEvent(Arcade::MouseEvent::Type event) :
    Event(Arcade::Event::Type::MOUSE_EVENT),
    _type(event), _pos({0, 0})
{
}

Arcade::MouseEvent::MouseEvent(Arcade::MouseEvent::Type event, Arcade::Pos pos) :
    Event(Arcade::Event::Type::MOUSE_EVENT, pos),
    _type(event), _pos(pos)
{
}

Arcade::MouseEvent::~MouseEvent()
{
}
