/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NcursesEvent
*/

#include "NcursesEvent.hpp"

Arcade::NcursesEvent::NcursesEvent(int key)
{
    MEVENT mouse_event;

    _data = "";
    if (key == KEY_MOUSE) {
        getmouse(&mouse_event);
        _pos = {mouse_event.x, mouse_event.y};
        if (mouse_event.bstate & BUTTON1_CLICKED)
            _key = 0;
        else if (mouse_event.bstate & BUTTON3_CLICKED)
            _key = 1;
        else
            _key = 400;
    } else {
        _pos = {-1, -1};
        _key = key;
    }
}

Arcade::NcursesEvent::~NcursesEvent()
{
}

std::size_t Arcade::NcursesEvent::getKey() const
{
    return _key;
}

void Arcade::NcursesEvent::setKey(std::size_t key)
{
    _key = key;
}

Arcade::Pos Arcade::NcursesEvent::getMousePos() const
{
    return _pos;
}

std::string Arcade::NcursesEvent::getData() const
{
    return _data;
}