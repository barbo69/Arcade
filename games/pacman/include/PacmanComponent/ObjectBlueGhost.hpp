/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectBlueGhost
*/

#ifndef OBJECTBLUEGHOST_HPP_
#define OBJECTBLUEGHOST_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectBlueGhost : public ComponentObject {
        public:
            ObjectBlueGhost(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectBlueGhost();

        protected:
        private:
    };
}


#endif /* !OBJECTBLUEGHOST_HPP_ */
