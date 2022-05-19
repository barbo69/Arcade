/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentObject
*/

#ifndef COMPONENTOBJECT_HPP_
#define COMPONENTOBJECT_HPP_

#include "PacmanComponent.hpp"
#include "PacmanMap.hpp"

namespace Arcade {

    enum class ComponentObjectType {
        BASIC,
        PACMAN,
        RED_GHOST,
        PINK_GHOST,
        BLUE_GHOST,
        YELLOW_GHOST,
        MAP,
        LIT_PAC_GUM,
        BIG_PAC_GUM
    };

    class ComponentObject : public PacmanComponent {
        public:
            ComponentObject(
                const std::size_t &id,
                const std::string &file,
                const ComponentObjectType &type
            );
            ~ComponentObject();
            ComponentObjectType getComponentObjectType() const override;
            void setX(const size_t x);
            int getX() const override;
            void setY(const size_t y); 
            int getY() const override;
            void setWidth(const int width);
            int getWidth() const override;
            void setHeight(const int height);
            int getHeight() const override;
            void setRect(const Rect rect);
            Rect getRect() const override;
            void setObjectAnimation(const PacmanAnimType &type);
            void setObjectCurrentAnimation(const PacmanAnimMove &move);
            void animateObject();
            static IPacCompUPtr makeObject(
                const std::size_t &id,
                const PacmanMap::Pos &pos,
                const ComponentObjectType &type
            );

        private:
            const ComponentObjectType _type;
            int _x;
            int _y;
            int _width;
            int _height;
            Rect _rect;
            IPacAnimUptr _anim;
    };
}

#endif /* !COMPONENTOBJECT_HPP_ */
