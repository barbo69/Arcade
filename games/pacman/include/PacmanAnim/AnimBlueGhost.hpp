/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimBlueGhost
*/

#ifndef ANIMBLUEGHOST_HPP_
#define ANIMBLUEGHOST_HPP_

#include "PacmanAnim.hpp"

namespace Arcade {
    class AnimBlueGhost : public PacmanAnim {
        public:
            AnimBlueGhost();
            ~AnimBlueGhost();

        private:
            void _setLeftAnim();
            void _setRightAnim();
            void _setDownAnim();
            void _setUpAnim();
            void _setWeaknessAnim();
            void _setDeathAnim();
    };
}

#endif /* !ANIMBLUEGHOST_HPP_ */
