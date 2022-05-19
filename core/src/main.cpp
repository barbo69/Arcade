/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** main
*/


#include "../include/Core.hpp"

namespace Arcade {

    enum RunningStatus {
        R_RUN,
        R_PAUSE,
        R_QUIT
    };

}

int main(int ac, char **av)
{
    Arcade::Core core;
    int err = 0;

    if ((err = core.errorHandling(ac, av)) != 0)
        return err;

    core.run();
    return 0;
}
