/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanAnim
*/

#ifndef PACMANANIM_HPP_
#define PACMANANIM_HPP_

#include "IPacmanAnim.hpp"
#include <memory>

namespace Arcade {

    using IPacAnimUptr = std::unique_ptr<IPacmanAnim>;

    class PacmanAnim : public IPacmanAnim {
        public:
            PacmanAnim();
            ~PacmanAnim();
            void setAnim(
                const RectList &rectList,
                const float &delay,
                const PacmanAnimMove &type
            );
            void setCurrentAnim(const PacmanAnimMove &currentAnim);
            PacmanAnimMove getCurrentAnim(void) const;
            Rect animate();
            static IPacAnimUptr makeAnim(const PacmanAnimType &type);

        protected:
            Rect _currentRect;
            PacmanAnimMove _currentAnim;
            std::chrono::time_point<std::chrono::high_resolution_clock> _lastTime;
            float _delay;
            AnimTypeRectListMap _map;
            void _changeRectPos(RectList &list, const PacmanAnimMove &type);

    };
}

#endif /* !PACMANANIM_HPP_ */
