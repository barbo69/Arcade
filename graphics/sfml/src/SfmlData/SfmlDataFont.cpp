/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlDataFont
*/

#include "SfmlDataFont.hpp"

Arcade::SfmlDataFont::SfmlDataFont(const std::string &path)
: SfmlData(path, SfmlDataType::FONT)
{
    _font.loadFromFile(path + ".ttf");
}

Arcade::SfmlDataFont::~SfmlDataFont()
{
    
}

const sf::Font &Arcade::SfmlDataFont::getFont() const
{
    return _font;
}