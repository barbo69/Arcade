/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectRedGhost
*/

#ifndef OBJECT_RED_GHOST_HPP_
#define OBJECT_RED_GHOST_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectRedGhost : public ComponentObject {
        public:
            ObjectRedGhost(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectRedGhost();

        protected:
        private:
    };
}

#endif /* !OBJECT_RED_GHOST_HPP_ */
