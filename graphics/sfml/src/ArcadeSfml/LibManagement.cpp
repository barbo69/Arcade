/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManagement
*/

#include "ArcadeSfml.hpp"

Arcade::IDisplay *display;

__attribute__((__constructor__)) void onOpen()
{
    display = new Arcade::ArcadeSfml();
}

__attribute__((__destructor__)) void onClose()
{
    delete display;
}

extern "C" {
    unsigned char getLibType()
    {
        return 0;
    }

    Arcade::IDisplay *getDisplayInstance()
    {
        return display;
    }
};
