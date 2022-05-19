/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlDataFont
*/

#ifndef SFMLDATAFONT_HPP_
#define SFMLDATAFONT_HPP_

#include "SfmlData.hpp"

namespace Arcade {
    class SfmlDataFont : public SfmlData {
        public:
            SfmlDataFont(const std::string &path);
            ~SfmlDataFont();
            const sf::Font &getFont() const;

        private:
            sf::Font _font;
    };
}

#endif /* !SFMLDATAFONT_HPP_ */
