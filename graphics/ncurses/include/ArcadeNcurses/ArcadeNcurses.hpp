/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade NCurses
*/

#ifndef ARCADE_NCURSES_HPP_
#define ARCADE_NCURSES_HPP_

#include "IDisplay.hpp"
#include <curses.h>

namespace Arcade {

    using ICompUPtrVect = std::vector<std::unique_ptr<IComponent>>;
    using IEventUPtrVect = std::vector<std::unique_ptr<IEvent>>;

    class ArcadeNcurses : public IDisplay {
        public:
            ArcadeNcurses();
            ~ArcadeNcurses();
            void init();
            void stop();
            std::string getLibName() const;
            void display(ICompUPtrVect &components);
            IEventUPtrVect &getEvents();
            void clear();

        private:
            const std::string _name;
            IEventUPtrVect _events;
    };

}

#endif /* !ARCADE_NCURSES_HPP_ */
