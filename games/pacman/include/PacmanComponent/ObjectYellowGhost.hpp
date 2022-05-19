/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectYellowGhost
*/

#ifndef OBJECTYELLOWGHOST_HPP_
#define OBJECTYELLOWGHOST_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectYellowGhost : public ComponentObject {
        public:
            ObjectYellowGhost(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectYellowGhost();

        protected:
        private:
    };
}

#endif /* !OBJECTYELLOWGHOST_HPP_ */
