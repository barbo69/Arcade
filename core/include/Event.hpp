/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "../../include/IEvent.hpp"

namespace Arcade {

    class Event : public IEvent {
        public:

            enum Type {
                MOUSE_EVENT,
                KEY_EVENT,
                WIN_EVENT,
                NONE
            };

            /**
             * @brief Constructor with no arguments.
             * Initialize _type with Type::NONE, _key with 0 and _pos with {0, 0}
             */
            Event();
            /**
             * @brief Constructor with the event type argument.
             * Initialize _type with the event given, _key with 0,
             * and _pos with {0, 0}.
             */
            Event(Type event);
            /**
             * @brief Constructor with the event type and key arguments.
             * Initialize _type with the event given, _key with the key given,
             * and _pos with {0, 0}.
             */
            Event(Type event, size_t key);
            /**
             * @brief Constructor with the event type and mouse position arguments.
             * Initialize _type with the event given, _key with 0,
             * and _pos with the position given.
             */
            Event(Type event, Pos pos);
            /**
             * @brief Constructor with the event type, key and mouse position arguments.
             * Initialize _type with the event given, _key with the key given,
             * and _pos with the position given.
             */
            Event(Type event, size_t key, Pos pos);
            /**
             * @brief Just a destructor, nothing to see here.
             */
            ~Event();

            /**
             * @brief Get the Key value of the event
             *
             * @return std::size_t
             */
            std::size_t getKey() const;
            /**
             * @brief Set the Key value of the event.
             * This is only to be used by the core, to uniformize
             * the value between different libraries.
             * @param key
             * @return std::size_t
             */
            void setKey(std::size_t const key);
            /**
             * @brief Get the Mouse Position
             * Position is expressed in the Pos structure {x, y}
             * @return Pos
             */
            Pos getMousePos() const;

        private:
            const Type _type;
            size_t _key;
            Pos _pos;


    };

}

#endif /* EVENT_HPP */
