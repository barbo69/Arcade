/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Timer
*/

#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

namespace Arcade {

    class Timer {
        public:
            Timer();
            ~Timer();
            void start();
            void pause();
            void reset();
            std::chrono::duration<double> getElapsedTime() const;
        private:
            std::chrono::time_point<std::chrono::system_clock> _start;
            bool _paused = true;
    };
}

#endif /* !TIMER_H_ */
