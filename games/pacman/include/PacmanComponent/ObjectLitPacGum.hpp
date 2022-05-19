/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectLitPacGum
*/

#ifndef OBJECTLITPACGUM_HPP_
#define OBJECTLITPACGUM_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectLitPacGum : public ComponentObject {
        public:
            ObjectLitPacGum(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectLitPacGum();

        protected:
        private:
    };
}

#endif /* !OBJECTLITPACGUM_HPP_ */
