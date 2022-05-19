/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponentObject
*/

#ifndef SFMLCOMPONENTOBJECT_HPP_
#define SFMLCOMPONENTOBJECT_HPP_

#include "SfmlComponent.hpp"

namespace Arcade {
    class SfmlComponentObject : public SfmlComponent {
        public:
            SfmlComponentObject(
                const size_t &id,
                const std::unique_ptr<ISfmlData> &data
            );
            ~SfmlComponentObject();
            void setPos(const int x, const int y);
            sf::Vector2f getPos() const override;
            void setRect(const Rect rect);
            sf::IntRect getRect() const override;
            void setWidth(const int width);
            int getWidth() const;
            void setHeight(const int height);
            int getHeight() const;
            void draw(sf::RenderWindow &window);

        private:
            sf::Sprite _sprite;
            sf::Vector2f _scale;
            int _width;
            int _height;
    };
};

#endif /* !SFMLCOMPONENTOBJECT_HPP_ */
