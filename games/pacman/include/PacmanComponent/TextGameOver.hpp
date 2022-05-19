/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextGameOver
*/

#ifndef TEXTGAMEOVER_HPP_
#define TEXTGAMEOVER_HPP_

#include "ComponentText.hpp"

namespace Arcade {
    class TextGameOver : public ComponentText {
        public:
            TextGameOver(const std::size_t &id);
            ~TextGameOver();

        protected:
        private:
    };
}

#endif /* !TEXTGAMEOVER_HPP_ */
