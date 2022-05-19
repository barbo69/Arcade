/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ObjectMap
*/

#ifndef OBJECTMAP_HPP_
#define OBJECTMAP_HPP_

#include "ComponentObject.hpp"

namespace Arcade {
    class ObjectMap : public ComponentObject {
        public:
            ObjectMap(const std::size_t &id, const PacmanMap::Pos &pos);
            ~ObjectMap();

        protected:
        private:
    };

}
#endif /* !OBJECTMAP_HPP_ */
