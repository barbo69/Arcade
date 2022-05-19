/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** KeyEvent
*/

#ifndef KEY_EVENT_HPP_
#define KEY_EVENT_HPP_

#include "Event.hpp"

namespace Arcade {

    class KeyEvent : public Event {

        public:

            enum Type {
                KEY_PRESS,
                KEY_RELEASE,
                NONE
            };


            /**
             * @brief Constructor with no arguments.
             * Initialize _type with Type::NONE and _key with 0
             */
            KeyEvent();
            /**
             * @brief Constructor with the event type argument.
             * Initialize _type with the event given and _key with 0
             */
            KeyEvent(Type event);
            /**
             * @brief Constructor with the event type and key arguments.
             * Initialize _type with the event given and _key with the key given
             */
            KeyEvent(Type event, size_t key);
            /**
             * @brief Just a destructor, nothing to see here.
             */
            ~KeyEvent();


        private:
            const Type _type;
            size_t _key;

    };

}

#endif /* KEY_EVENT_HPP */
