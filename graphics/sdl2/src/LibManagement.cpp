/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManagement
*/

#include "Display.hpp"
#include <iostream>

Arcade::IDisplay *display;

__attribute__((__constructor__)) void onOpen()
{
    std::cout << "creating sdl2" << std::endl;
    display = new Display();
}

__attribute__((__destructor__)) void onClose()
{
    std::cout << "using destructor from sdl2" << std::endl;
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
