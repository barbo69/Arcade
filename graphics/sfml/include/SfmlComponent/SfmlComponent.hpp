/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlComponent
*/

#ifndef SFMLCOMPONENT_HPP_
#define SFMLCOMPONENT_HPP_

#include "ISfmlComponent.hpp"
#include "ISfmlData.hpp"
#include "GameDimension.hpp"

namespace Arcade {

    class SfmlComponent : public ISfmlComponent {
        public:
            SfmlComponent(
                const size_t &id,
                const IComponent::Type &type,
                const std::unique_ptr<ISfmlData> &data
            );
            ~SfmlComponent();
            std::size_t getId() const;
            IComponent::Type getType() const;
            std::string getFile() const;
            virtual void setPos(const int x, const int y);
            virtual sf::Vector2f getPos() const;
            virtual void setRect(const Rect rect);
            virtual sf::IntRect getRect() const;
            virtual void setWidth(const int width);
            virtual int getWidth() const;
            virtual void setHeight(const int height);
            virtual int getHeight() const;
            virtual void setFontSize(const int fontSize);
            virtual int getFontSize() const;
            virtual void setText(const std::string &text);
            virtual std::string getText() const;
            virtual void draw(sf::RenderWindow &window);
            void setUse(bool use);
            bool isUsed() const;
            static std::unique_ptr<ISfmlComponent> sfmlComponentFactory(
                const size_t &id,
                const IComponent::Type &type,
                const std::unique_ptr<ISfmlData> &data
            );

        protected:
            const size_t _id;
            const IComponent::Type _type;
            const std::unique_ptr<ISfmlData> &_data;
            bool _use;

            

    };
}

#endif /* !SFMLCOMPONENT_HPP_ */
