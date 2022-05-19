/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlDataSound
*/

#include "SfmlDataSound.hpp"

Arcade::SfmlDataSound::SfmlDataSound(const std::string &path)
: SfmlData(path, SfmlDataType::SOUND)
{
    _sound.loadFromFile(path + ".ogg");
}

Arcade::SfmlDataSound::~SfmlDataSound()
{

}

const sf::SoundBuffer &Arcade::SfmlDataSound::getSound() const
{
    return _sound;
}