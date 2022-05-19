/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlDataTexture
*/

#include "SfmlDataTexture.hpp"
#include <iostream>

Arcade::SfmlDataTexture::SfmlDataTexture(const std::string &path)
: SfmlData(path, SfmlDataType::TEXTURE)
{
    _texture.loadFromFile(path + ".png");
}

Arcade::SfmlDataTexture::~SfmlDataTexture()
{
    
}

const sf::Texture &Arcade::SfmlDataTexture::getTexture() const
{
    return _texture;
}