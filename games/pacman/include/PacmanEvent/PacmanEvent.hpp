/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanEvent
*/

#ifndef PACMANEVENT_HPP_
#define PACMANEVENT_HPP_

#include "IEvent.hpp"

namespace Arcade {
    class PacmanEvent : public IEvent {
        public:
            PacmanEvent(const std::size_t key);
            PacmanEvent(const std::size_t &key, const std::string &data);
            ~PacmanEvent();
            std::size_t getKey() const;
            void setKey(std::size_t const key);
            Pos getMousePos() const;
            std::string getData() const;

        private:
            size_t _key;
            Pos _mouse;
            std::string _data;
    };   
}

#endif /* !PACMANEVENT_HPP_ */
