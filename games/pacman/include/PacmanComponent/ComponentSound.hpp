/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentSound
*/

#ifndef COMPONENTSOUND_HPP_
#define COMPONENTSOUND_HPP_

#include "PacmanComponent.hpp"

namespace Arcade {
    class ComponentSound : public PacmanComponent {
        public:
            ComponentSound(const std::size_t &id, const std::string &file);
            ~ComponentSound();

        private:
    };
}

#endif /* !COMPONENTSOUND_HPP_ */
