/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Component
*/

#include "Component.hpp"

namespace Arcade {
    Component::Component(int id, Type type, std::string file, Rect rect, int x, int y, int w, int h):
    _id(id), _type(type), _file(file), _x(x), _y(y), _w(w), _h(h), _rect(rect)
    {}

    Component::Component(int id, std::string text, std::string file, Rect rect, int x, int y, int w, int h, int fontSize):
    _id(id), _type(Type::TEXT), _file(file), _x(x), _y(y), _w(w), _h(h), _rect(rect), _text(text), _fontSize(fontSize)
    {}

    Component::~Component()
    {}

    std::size_t Component::getId() const
    {
        return _id;
    }

    Arcade::IComponent::Type Component::getType() const
    {
        return _type;
    }

    std::string Component::getFile() const
    {
        return _file;
    }

    int Component::getX() const
    {
        return _x;
    }
    int Component::getY() const
    {
        return _y;
    }

    void Component::setX(std::size_t x)
    {
        _x = x;
    }
    void Component::setY(std::size_t y)
    {
        _y = y;
    }

    int Component::getWidth() const
    {
        return _w;
    }
    int Component::getHeight() const
    {
        return _h;
    }

    void Component::setWidth(const int width)
    {
        _w = width;
    }
    void Component::setHeight(const int height)
    {
        _h = height;
    }

    Rect Component::getRect() const
    {
        return _rect;
    }

    void Component::setRect(Rect const rect)
    {
        _rect = rect;
    }

    std::string Component::getText() const
    {
        return _text;
    }

    void Component::setText(std::string const text)
    {
        _text = text;
    }

    int Component::getFontSize() const
    {
        return _fontSize;
    }
}