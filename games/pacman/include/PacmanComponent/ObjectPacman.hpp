/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectPacman
*/

#ifndef OBJECTPACMAN_HPP_
#define OBJECTPACMAN_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectPacman : public ComponentObject {
        public:
            ObjectPacman(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectPacman();
    };
}

#endif /* !OBJECTPACMAN_HPP_ */
