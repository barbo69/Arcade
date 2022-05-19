/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponentSound
*/

#ifndef SFMLCOMPONENTSOUND_HPP_
#define SFMLCOMPONENTSOUND_HPP_

#include "SfmlComponent.hpp"

namespace Arcade {
    class SfmlComponentSound : public SfmlComponent {
        public:
            SfmlComponentSound(
                const size_t &id,
                const std::unique_ptr<ISfmlData> &data
            );
            ~SfmlComponentSound();

        private:
            sf::Sound _sound;
    };
}

#endif /* !SFMLCOMPONENTSOUND_HPP_ */
