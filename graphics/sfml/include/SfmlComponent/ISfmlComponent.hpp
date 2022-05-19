/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ISfmlComponent
*/

#ifndef ISFMLCOMPONENT_HPP_
#define ISFMLCOMPONENT_HPP_

#include "IComponent.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

namespace Arcade {

    class ISfmlComponent {
        public:
            virtual ~ISfmlComponent() = default;
            virtual std::size_t getId() const = 0;
            virtual IComponent::Type getType() const = 0;
            virtual std::string getFile() const = 0;
            virtual void setPos(const int x, const int y) = 0;
            virtual sf::Vector2f getPos() const = 0;
            virtual void setRect(const Rect rect) = 0;
            virtual void setWidth(const int width) = 0;
            virtual int getWidth() const = 0;
            virtual void setHeight(const int height) = 0;
            virtual int getHeight() const = 0;
            virtual void setFontSize(const int fontSize) = 0;
            virtual int getFontSize() const = 0;
            virtual sf::IntRect getRect() const = 0;
            virtual void setText(const std::string &text) = 0;
            virtual std::string getText() const = 0;
            virtual void draw(sf::RenderWindow &window) = 0;
            virtual void setUse(bool use) = 0;
            virtual bool isUsed() const = 0;
};
    
}

#endif /* !ISFMLCOMPONENT_HPP_ */
