/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentText
*/

#include "ComponentText.hpp"
#include "TextGameOver.hpp"
#include "TextWin.hpp"
#include "TextScore.hpp"
#include "TextScoreNb.hpp"
#include "TextReset.hpp"

Arcade::ComponentText::ComponentText(
    const std::size_t &id,
    const std::string &file,
    const ComponentTextType &type
)
: PacmanComponent(id, IComponent::TEXT, file), _type(type)
{
    _rect = { 0, 0, 0, 0 };
    _x = 0;
    _y = 0; 
    _width = 0;
    _height = 0;
    _fontSize = 0;
}

Arcade::ComponentText::~ComponentText()
{
    
}

Arcade::ComponentTextType Arcade::ComponentText::getComponentTextType() const
{
    return _type;
}

void Arcade::ComponentText::setX(const size_t x)
{
    _x = x;
}

int Arcade::ComponentText::getX() const
{
    return _x;
}

void Arcade::ComponentText::setY(const size_t y)
{
    _y = y; 
} 

int Arcade::ComponentText::getY() const
{
    return _y;   
}

void Arcade::ComponentText::setWidth(const int width)
{
    _width = width;
}

int Arcade::ComponentText::getWidth() const
{
    return _width;   
}

void Arcade::ComponentText::setHeight(const int height)
{
    _height = height;   
}

int Arcade::ComponentText::getHeight() const
{
    return _height;   
}

void Arcade::ComponentText::setRect(Rect const rect)
{
    _rect = rect;
}

Arcade::Rect Arcade::ComponentText::getRect() const
{
    return _rect;
}


void Arcade::ComponentText::setFontSize(const int size)
{
    _fontSize = size;
}

int Arcade::ComponentText::getFontSize() const
{
    return _fontSize;
}

void Arcade::ComponentText::setText(const std::string text)
{
    _text = text;
}

std::string Arcade::ComponentText::getText() const
{
    return _text;
}

Arcade::IPacCompUPtr Arcade::ComponentText::makeText(
    const std::size_t &id,
    const ComponentTextType &type
)
{
    switch (type) {
        case ComponentTextType::GAME_OVER:
            return std::make_unique<TextGameOver>(id);
        case ComponentTextType::WIN:
            return std::make_unique<TextWin>(id);
        case ComponentTextType::SCORE:
            return std::make_unique<TextScore>(id);
        case ComponentTextType::SCORE_NB:
            return std::make_unique<TextScoreNb>(id);
        case ComponentTextType::TEXT_RESET:
            return std::make_unique<TextReset>(id);
    }
    return nullptr;
}
