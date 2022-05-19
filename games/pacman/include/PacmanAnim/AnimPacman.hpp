/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimPacman
*/

#ifndef ANIMPACMAN_HPP_
#define ANIMPACMAN_HPP_

#include "PacmanAnim.hpp"

namespace Arcade {
    class AnimPacman : public PacmanAnim {
        public:
            AnimPacman();
            ~AnimPacman();

        private:
            void _setLeftAnim();
            void _setRightAnim();
            void _setDownAnim();
            void _setUpAnim();
            void _setDeathAnim();
    };
}

#endif /* !ANIMPACMAN_HPP_ */
