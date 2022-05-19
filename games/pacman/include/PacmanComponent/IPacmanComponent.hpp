/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** IPacmanComponent
*/

#ifndef IPACMANCOMPONENT_HPP_
#define IPACMANCOMPONENT_HPP_

#include "IComponent.hpp"
#include "PacmanAnim.hpp"

namespace Arcade {

    enum class ComponentObjectType;

    enum class ComponentTextType;

    class IPacmanComponent : public IComponent {
        public:
            ~IPacmanComponent() = default;
            virtual std::size_t getId() const = 0;
            virtual Type getType() const = 0;
            virtual ComponentObjectType getComponentObjectType() const = 0;
            virtual ComponentTextType getComponentTextType() const = 0;
            virtual std::string getFile() const = 0;
            virtual void setX(std::size_t const x) = 0;
            virtual int getX() const override = 0;
            virtual void setY(std::size_t const y) = 0;
            virtual int getY() const override = 0;
            virtual void setWidth(const int width) = 0;
            virtual int getWidth() const override = 0;
            virtual void setHeight(const int height) = 0;
            virtual int getHeight() const override = 0;
            virtual void setRect(Rect const rect) = 0;
            virtual Rect getRect() const override = 0;
            virtual void setFontSize(const int size) = 0;
            virtual int getFontSize() const override = 0;
            virtual void setText(std::string const text) = 0;
            virtual std::string getText() const override = 0;
            virtual void setObjectAnimation(const PacmanAnimType &type) = 0;
            virtual void setObjectCurrentAnimation(
                const PacmanAnimMove &move
            ) = 0;
            virtual void animateObject() = 0;
    };
}

#endif /* !IPACMANCOMPONENT_HPP_ */
