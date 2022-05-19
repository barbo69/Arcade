/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Event
*/

#include "../../../include/IEvent.hpp"

#ifndef EVENT_HPP_
    #define EVENT_HPP_

class Event: public Arcade::IEvent {
    public:
        Event(std::size_t key);
        Event(std::size_t key, int x, int y);
        ~Event();
        std::size_t getKey() const;
        void setKey(std::size_t const key);
        Arcade::Pos getMousePos() const;
        std::string getData() const;
    private:
        std::size_t _key;
        int _x;
        int _y;
};

#endif /* !EVENT_HPP_ */
