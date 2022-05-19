/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** SfmlData
*/

#ifndef SFMLDATA_HPP_   
#define SFMLDATA_HPP_

#include "ISfmlData.hpp"
#include "IComponent.hpp"

namespace Arcade {

    using ISfmlDataUPtr = std::unique_ptr<ISfmlData>;

    class SfmlData : public ISfmlData {
        public:
            SfmlData(const std::string &path, const SfmlDataType &type);
            ~SfmlData();
            std::string getPath() const;
            SfmlDataType getType() const;
            virtual const sf::Font &getFont() const;
            virtual const sf::SoundBuffer &getSound() const;
            virtual const sf::Texture &getTexture() const;
            static ISfmlDataUPtr SfmlDataFactory(
                const std::string &path,
                const IComponent::Type &type
            );
            

        protected:
            const std::string _path;
            const SfmlDataType _type;
    };
};

#endif /* !SFMLDATA_HPP_ */
