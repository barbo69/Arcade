/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponentSound
*/

#include "SfmlComponentSound.hpp"

Arcade::SfmlComponentSound::SfmlComponentSound(
    const size_t &id,
    const std::unique_ptr<ISfmlData> &data
)
: SfmlComponent(id, IComponent::SOUND, data)
{
    if (data->getType() != SfmlDataType::SOUND)
        throw std::runtime_error("Wrong data type");
    _sound.setBuffer(data->getSound());  
    _sound.play();
}

Arcade::SfmlComponentSound::~SfmlComponentSound()
{
    
}