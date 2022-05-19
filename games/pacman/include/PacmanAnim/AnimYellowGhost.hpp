/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** AnimYellowGhost
*/

#ifndef ANIMYELLOWGHOST_HPP_
#define ANIMYELLOWGHOST_HPP_

#include "PacmanAnim.hpp"

namespace Arcade {
    class AnimYellowGhost : public PacmanAnim {
        public:
            AnimYellowGhost();
            ~AnimYellowGhost();

        private:
            void _setLeftAnim();
            void _setRightAnim();
            void _setDownAnim();
            void _setUpAnim();
            void _setWeaknessAnim();
            void _setDeathAnim();
    };
}

#endif /* !ANIMYELLOWGHOST_HPP_ */
