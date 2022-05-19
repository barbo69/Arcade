/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Timer
*/

#include "../include/Timer.hpp"

namespace Arcade {

    Timer::Timer()
    {}

    Timer::~Timer()
    {}


    void Timer::start()
    {
        _paused = false;
        _start = std::chrono::system_clock::now();
    }

    void Timer::pause()
    {
        _paused = true;
    }

    void Timer::reset()
    {
        _start = std::chrono::system_clock::now();
    }

    std::chrono::duration<double> Timer::getElapsedTime() const
    {
        return std::chrono::system_clock::now() - _start;
    }
}
