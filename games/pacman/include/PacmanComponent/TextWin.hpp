/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextWin
*/

#ifndef TEXTWIN_HPP_
#define TEXTWIN_HPP_

#include "ComponentText.hpp"

namespace Arcade {
    class TextWin : public ComponentText {
        public:
            TextWin(const std::size_t &id);
            ~TextWin();
    };
}

#endif /* !TEXTWIN_HPP_ */
