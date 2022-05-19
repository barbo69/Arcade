/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ISfmlData
*/

#ifndef IARCADESFMLDATA_HPP_
#define IARCADESFMLDATA_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

namespace Arcade {
    enum class SfmlDataType {
        FONT,
        SOUND,
        TEXTURE
    };
    class ISfmlData {
        public:
            virtual ~ISfmlData() = default;
            virtual std::string getPath() const = 0;
            virtual SfmlDataType getType() const = 0;
            virtual const sf::Font &getFont() const = 0;
            virtual const sf::SoundBuffer &getSound() const = 0;
            virtual const sf::Texture &getTexture() const = 0;
    };
}

#endif /* !IARCADESFMLDATA_HPP_ */
