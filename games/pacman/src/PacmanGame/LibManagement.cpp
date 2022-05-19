/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibManagement
*/

#include "PacmanGame.hpp"

Arcade::IGame *game;

__attribute__((__constructor__)) void onOpen()
{
    game = new Arcade::PacmanGame;
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
