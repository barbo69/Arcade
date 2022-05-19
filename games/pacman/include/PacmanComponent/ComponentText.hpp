/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentText
*/

#ifndef COMPONENTTEXT_HPP_
#define COMPONENTTEXT_HPP_

#include "PacmanComponent.hpp"

namespace Arcade {

    enum class ComponentTextType {
        BASIC,
        GAME_OVER,
        WIN,
        SCORE,
        SCORE_NB,
        TEXT_RESET,
        PLAYER_NAME
    };

    class ComponentText : public PacmanComponent {
        public:
            ComponentText(
                const std::size_t &id,
                const std::string &file,
                const ComponentTextType &type
            );
            ~ComponentText();
            ComponentTextType getComponentTextType() const override;
            void setX(const size_t x);
            int getX() const override;
            void setY(const size_t y); 
            int getY() const override;
            void setWidth(const int width);
            int getWidth() const override;
            void setHeight(const int height);
            int getHeight() const override;
            void setRect(Rect const rect);
            Rect getRect() const override;
            void setFontSize(const int size);
            int getFontSize() const override;
            void setText(const std::string text);
            std::string getText() const override;
            static IPacCompUPtr makeText(const std::size_t &id,
            const ComponentTextType &type);

        private:
            const ComponentTextType _type;
            int _x;
            int _y;
            int _width;
            int _height;
            int _fontSize;
            std::string _text;
            Rect _rect;
    };
}

#endif /* !COMPONENTTEXT_HPP_ */
