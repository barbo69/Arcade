/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** IPacmanAnim
*/

#ifndef IPACMANANIM_HPP_
#define IPACMANANIM_HPP_

#include "IComponent.hpp"
#include <list>
#include <map>
#include <chrono>

namespace Arcade {

    enum class PacmanAnimMove {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        DEATH,
        WEAKNESS,
        ENEMY_DEATH
    };

    enum class PacmanAnimType {
        PACMAN,
        RED_GHOST,
        PINK_GHOST,
        BLUE_GHOST,
        YELLOW_GHOST,  
    };

    using RectList = std::list<Rect>;
    using AnimTypeRectListPair = std::pair<PacmanAnimMove, RectList>;
    using AnimTypeRectListMap = std::map<PacmanAnimMove, RectList>;

    class IPacmanAnim {
        public:
            ~IPacmanAnim() = default;
            virtual void setAnim(
                const RectList &rectList,
                const float &delay,
                const PacmanAnimMove &type
            ) = 0;
            virtual void setCurrentAnim(const PacmanAnimMove &currentAnim) = 0;
            virtual PacmanAnimMove getCurrentAnim(void) const = 0;
            virtual Rect animate() = 0;
    };
}

#endif /* !IPACMANANIM_HPP_ */
