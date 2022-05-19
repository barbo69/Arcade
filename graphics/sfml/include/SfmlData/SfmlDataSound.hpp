/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlDataSound
*/

#ifndef SFMLDATASOUND_HPP_
#define SFMLDATASOUND_HPP_

#include "SfmlData.hpp"

namespace Arcade {
    class SfmlDataSound : public SfmlData {
        public:
            SfmlDataSound(const std::string &path);
            ~SfmlDataSound();
            const sf::SoundBuffer &getSound() const;

        private:
            sf::SoundBuffer _sound;

    };
};

#endif /* !SFMLDATASOUND_HPP_ */
