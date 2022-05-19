/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextScore
*/

#ifndef TEXTSCORE_HPP_
#define TEXTSCORE_HPP_

#include "ComponentText.hpp"

namespace Arcade {
    class TextScore : public ComponentText {
        public:
            TextScore(const std::size_t &id);
            ~TextScore();
    };
}

#endif /* !TEXTSCORE_HPP_ */
