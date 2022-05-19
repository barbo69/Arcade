/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextScoreNb
*/

#ifndef TEXTSCORENB_HPP_
#define TEXTSCORENB_HPP_

#include "ComponentText.hpp"

namespace Arcade {
    class TextScoreNb : public ComponentText {
        public:
            TextScoreNb(const std::size_t &id);
            ~TextScoreNb();
    };
}

#endif /* !TEXTSCORENB_HPP_ */
