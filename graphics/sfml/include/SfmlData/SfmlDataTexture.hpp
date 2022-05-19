/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlDataTexture
*/

#ifndef SFMLDATATEXTURE_HPP_
#define SFMLDATATEXTURE_HPP_

#include "SfmlData.hpp"

namespace Arcade {
    class SfmlDataTexture : public SfmlData {
        public:
            SfmlDataTexture(const std::string &path);
            ~SfmlDataTexture();
            const sf::Texture &getTexture() const;

        private:
            sf::Texture _texture;
    };
};

#endif /* !SFMLDATATEXTURE_HPP_ */
