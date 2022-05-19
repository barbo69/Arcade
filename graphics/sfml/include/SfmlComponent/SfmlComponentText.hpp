/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponentText
*/

#ifndef SFMLCOMPONENTTEXT_HPP_
#define SFMLCOMPONENTTEXT_HPP_

#include "SfmlComponent.hpp"

namespace Arcade {
    class SfmlComponentText : public SfmlComponent {
        public:
            SfmlComponentText(
                const size_t &id,
                const std::unique_ptr<ISfmlData> &data
            );
            ~SfmlComponentText();
            void setPos(const int x, const int y);
            sf::Vector2f getPos() const override;
            void setFontSize(const int fontSize);
            int getFontSize() const;
            void setText(const std::string &text);
            std::string getText() const override;
            void draw(sf::RenderWindow &window);

        private:
            sf::Text _text;
            sf::Vector2f _scale;
            int _width;
            int _height;
    };
};

#endif /* !SFMLCOMPONENTTEXT_HPP_ */
