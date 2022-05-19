/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** SfmlEvent
*/

#ifndef SFMLEVENT_HPP_
#define SFMLEVENT_HPP_

#include "IEvent.hpp"
#include <SFML/Graphics.hpp>
#include "GameDimension.hpp"

namespace Arcade {

    class SfmlEvent : public IEvent {

        public:
            SfmlEvent(const sf::Event &event, const sf::RenderWindow &window);
            ~SfmlEvent();
            std::size_t getKey() const;
            void setKey(std::size_t const key);
            Pos getMousePos() const;
            std::string getData() const;

        private:
            size_t _key;
            Pos _mousePos;

    };

}

#endif /* !SFMLEVENT_HPP_ */
