/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimPinkGhost
*/

#ifndef ANIMPINKGHOST_HPP_
#define ANIMPINKGHOST_HPP_

#include "PacmanAnim.hpp"

namespace Arcade {
    class AnimPinkGhost : public PacmanAnim {
        public:
            AnimPinkGhost();
            ~AnimPinkGhost();

        private:
            void _setLeftAnim();
            void _setRightAnim();
            void _setDownAnim();
            void _setUpAnim();
            void _setWeaknessAnim();
            void _setDeathAnim();
    };
}

#endif /* !ANIMPINKGHOST_HPP_ */
