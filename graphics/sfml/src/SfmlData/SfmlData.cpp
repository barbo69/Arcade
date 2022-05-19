/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** SfmlData
*/

#include "SfmlData.hpp"
#include "SfmlDataFont.hpp"
#include "SfmlDataSound.hpp"
#include "SfmlDataTexture.hpp"
#include <stdexcept>

Arcade::SfmlData::SfmlData(const std::string &path, const SfmlDataType &type)
: _path(path), _type(type)
{

}

Arcade::SfmlData::~SfmlData()
{

}

std::string Arcade::SfmlData::getPath() const
{
    return _path;
}

Arcade::SfmlDataType Arcade::SfmlData::getType() const
{
    return _type;
}

const sf::Font &Arcade::SfmlData::getFont() const
{
    throw std::runtime_error("Bad usage of SfmlDisplay Data");
}

const sf::SoundBuffer &Arcade::SfmlData::getSound() const
{
    throw std::runtime_error("Bad usage of SfmlDisplay Data");
}

const sf::Texture &Arcade::SfmlData::getTexture() const
{
    throw std::runtime_error("Bad usage of SfmlDisplay Data");
}

Arcade::ISfmlDataUPtr Arcade::SfmlData::SfmlDataFactory(
    const std::string &path,
    const IComponent::Type &type
) 
{
    switch (type) {
        case IComponent::TEXT:
            return std::make_unique<SfmlDataFont>(path);
        case IComponent::SOUND:
            return std::make_unique<SfmlDataSound>(path);
        case IComponent::OBJECT:
            return std::make_unique<SfmlDataTexture>(path);
    }
    throw std::runtime_error("Bad usage of SfmlDisplay Data");
}