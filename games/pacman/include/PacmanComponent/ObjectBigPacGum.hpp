/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectBigPacGum
*/

#ifndef OBJECTBIGPACGUM_HPP_
#define OBJECTBIGPACGUM_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectBigPacGum : public ComponentObject {
        public:
            ObjectBigPacGum(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectBigPacGum();

        protected:
        private:
    };
}

#endif /* !OBJECTBIGPACGUM_HPP_ */
