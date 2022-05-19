/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextReset
*/

#ifndef TEXTRESET_HPP_
#define TEXTRESET_HPP_

#include "ComponentText.hpp"

namespace Arcade {
    class TextReset : public ComponentText {
        public:
            TextReset(const std::size_t &id);
            ~TextReset();

        protected:
        private:
    };
}

#endif /* !TEXTRESET_HPP_ */
