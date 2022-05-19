/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** NibblerComponent
*/

#include "NibblerComponent.hpp"

namespace Arcade {
    NibblerComponent::NibblerComponent(int id, Type type, std::string file, Rect rect, int x, int y, int w, int h):
    _id(id), _type(type), _file(file), _x(x), _y(y), _w(w), _h(h), _rect(rect)
    {}

    NibblerComponent::NibblerComponent(int id, std::string text, std::string file, Rect rect, int x, int y, int w, int h, int fontSize):
    _id(id), _type(Type::TEXT), _file(file), _x(x), _y(y), _w(w), _h(h), _rect(rect), _text(text), _fontSize(fontSize)
    {}

    NibblerComponent::~NibblerComponent()
    {}

    std::size_t NibblerComponent::getId() const
    {
        return _id;
    }

    Arcade::IComponent::Type NibblerComponent::getType() const
    {
        return _type;
    }

    std::string NibblerComponent::getFile() const
    {
        return _file;
    }

    int NibblerComponent::getX() const
    {
        return _x;
    }
    int NibblerComponent::getY() const
    {
        return _y;
    }

    void NibblerComponent::setX(std::size_t x)
    {
        _x = x;
    }
    void NibblerComponent::setY(std::size_t y)
    {
        _y = y;
    }

    int NibblerComponent::getWidth() const
    {
        return _w;
    }
    int NibblerComponent::getHeight() const
    {
        return _h;
    }

    void NibblerComponent::setWidth(const int width)
    {
        _w = width;
    }
    void NibblerComponent::setHeight(const int height)
    {
        _h = height;
    }

    Rect NibblerComponent::getRect() const
    {
        return _rect;
    }

    void NibblerComponent::setRect(Rect const rect)
    {
        _rect = rect;
    }

    std::string NibblerComponent::getText() const
    {
        return _text;
    }

    void NibblerComponent::setText(std::string const text)
    {
        _text = text;
    }

    int NibblerComponent::getFontSize() const
    {
        return _fontSize;
    }
}