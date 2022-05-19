/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentSound
*/

#include "ComponentSound.hpp"

Arcade::ComponentSound::ComponentSound(
    const std::size_t &id,
    const std::string &file
)
: PacmanComponent(id, IComponent::SOUND, file)
{
}

Arcade::ComponentSound::~ComponentSound()
{
}
