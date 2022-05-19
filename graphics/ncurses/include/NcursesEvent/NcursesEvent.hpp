/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NcursesEvent
*/

#ifndef NCURSES_EVENT_HPP_
#define NCURSES_EVENT_HPP_

#include "IEvent.hpp"
#include <curses.h>

namespace Arcade {

    class NcursesEvent : public IEvent {

        public:
            NcursesEvent(int event);
            ~NcursesEvent();

            std::size_t getKey() const;
            void setKey(std::size_t const key);
            Pos getMousePos() const;
            std::string getData() const;

        private:
            std::size_t _key;
            Pos _pos;
            std::string _data;

    };
}

#endif
