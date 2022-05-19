/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManagement
*/

#include "NibblerGame.hpp"

Arcade::IGame *game;

__attribute__((__constructor__)) void onOpen()
{
    game = new Arcade::NibblerGame();
}

__attribute__((__destructor__)) void onClose()
{
    delete game;
}

extern "C" {
    unsigned char getLibType()
    {
        return 1;
    }

    Arcade::IGame *getGameInstance()
    {
        return game;
    }
};
