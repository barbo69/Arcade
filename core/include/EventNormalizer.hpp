/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** eventNormalization
*/

#ifndef EVENTNORMALIZATION_HPP_
#define EVENTNORMALIZATION_HPP_

#include <cstddef>
#include <memory>
#include <vector>
#include <curses.h>
#include "IEvent.hpp"
#include "keyCodes.hpp"

typedef std::size_t keycode_t;




enum lib_t {
    SFML,
    SDL,
    NCURSES
};


const keycode_t functionKeyEquivalents[][NB_LIBS] { // {SFML, SDL2, Ncurses}
    {Keycodes::ESC, 27, 27},
    {Keycodes::ARROW_LEFT, 1073741904, 0404},
    {Keycodes::ARROW_RIGHT, 1073741903, 0405},
    {Keycodes::ARROW_UP, 1073741906, 0403},
    {Keycodes::ARROW_DOWN, 1073741905, 0402},
    {Keycodes::LEFT, 1, 0},
    {Keycodes::SPACE, 32, 32},
    {Keycodes::ENTER, 13, 10},
    {Keycodes::BACKSPACE, 8, 8},
};


class EventNormalizer {
    class ENException: public std::exception {
        public:
            ENException(std::string msg);
            ~ENException();
            const char *what() const noexcept override;
        private:
            const std::string _msg;
    };
    public:
        EventNormalizer();
        ~EventNormalizer();
        void normalizeEvents(std::vector<std::unique_ptr<Arcade::IEvent>> &events, const std::string &name);

    private:
        void _normalize(std::unique_ptr<Arcade::IEvent>& e, lib_t lib);
        keycode_t _findSpecialCode(keycode_t code, lib_t lib);

};


#endif /* !EVENTNORMALIZATION_HPP_ */
