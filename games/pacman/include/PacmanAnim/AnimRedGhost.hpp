/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimRedGhost
*/

#ifndef ANIMREDGHOST_HPP_
#define ANIMREDGHOST_HPP_

#include "PacmanAnim.hpp"

namespace Arcade {
    class AnimRedGhost : public PacmanAnim {
        public:
            AnimRedGhost();
            ~AnimRedGhost();

        private:
            void _setLeftAnim();
            void _setRightAnim();
            void _setDownAnim();
            void _setUpAnim();
            void _setWeaknessAnim();
            void _setDeathAnim();
    };
}

#endif /* !ANIMREDGHOST_HPP_ */
