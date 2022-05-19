/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** NibblerComponent
*/

#ifndef COMPONENT_HPP_
    #define COMPONENT_HPP_

#include <string>
#include "../../../include/IComponent.hpp"

namespace Arcade {


    class NibblerComponent: public IComponent {
        public:
            NibblerComponent(int id, Type type, std::string file, Rect rect, int x, int y, int w, int h);
            NibblerComponent(int id, std::string text, std::string file, Rect rect, int x, int y, int w, int h, int fontSize);
            ~NibblerComponent();
            std::size_t getId() const;
            Type getType() const;   // Get component type
            std::string getFile() const;
            int getX() const;
            int getY() const;
            virtual void setX(std::size_t x);
            virtual void setY(std::size_t y);
            int getWidth() const;
            int getHeight() const;
            void setWidth(const int width);
            void setHeight(const int height);
            Rect getRect() const;
            void setRect(Rect const rect);
            std::string getText() const;    // Get text (TEXT)
            void setText(std::string const text);
            int getFontSize() const;
        protected:
            std::size_t _id;
            Type _type;
            std::string _file;
            int _x;
            int _y;
            int _w;
            int _h;
            Rect _rect;
            std::string _text;
            int _fontSize;
    };
}

#endif /* !ICOMPONENT_HPP */
