/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectPinkGhost
*/

#ifndef OBJECTPINKGHOST_HPP_
#define OBJECTPINKGHOST_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectPinkGhost : public ComponentObject {
        public:
            ObjectPinkGhost(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectPinkGhost();

        protected:
        private:
    };
}

#endif /* !OBJECTPINKGHOST_HPP_ */
