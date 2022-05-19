/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponentText
*/

#include "SfmlComponentText.hpp"

Arcade::SfmlComponentText::SfmlComponentText(
    const size_t &id,
    const std::unique_ptr<ISfmlData> &data
)
: SfmlComponent(id, IComponent::TEXT, data)
{
    if (data->getType() != SfmlDataType::FONT)
        throw std::runtime_error("Wrong data type");
    _text.setFont(data->getFont());
    _scale = _text.getScale();
    _width = 0;
    _height = 0;
}

Arcade::SfmlComponentText::~SfmlComponentText()
{
    
}

void Arcade::SfmlComponentText::setPos(const int x, const int y)
{
    sf::Vector2f pos = { static_cast<float>(x), static_cast<float>(y) };

    _text.setPosition(pos);
}

sf::Vector2f Arcade::SfmlComponentText::getPos() const
{
    return _text.getPosition();
}

void Arcade::SfmlComponentText::setFontSize(const int fontSize)
{
    _text.setCharacterSize(static_cast<unsigned int>(fontSize * 3.5));
}

int Arcade::SfmlComponentText::getFontSize() const
{
    return static_cast<unsigned int>(_text.getCharacterSize());
}


void Arcade::SfmlComponentText::setText(const std::string &text)
{
    _text.setString(text);
}

std::string Arcade::SfmlComponentText::getText() const
{
    return _text.getString();
}

void Arcade::SfmlComponentText::draw(sf::RenderWindow &window)
{
    window.draw(_text);
}
