/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MouseEvent
*/

#ifndef MOUSE_EVENT_HPP_
#define MOUSE_EVENT_HPP_

#include "Event.hpp"

namespace Arcade {

    class MouseEvent : public Event {

        public:

            enum Type {
                MOUSE_MOVED,
                MOUSE_ENTER,
                MOUSE_LEAVE,
                RIGHT_CLICK,
                LEFT_CLICK,
                MIDDLE_CLICK,
                NONE
            };


            /**
             * @brief Constructor with no arguments.
             * Initialize _type with Type::NONE and _pos with {0, 0}.
             */
            MouseEvent();
            /**
             * @brief Constructor with the event type argument.
             * Initialize _type with the event given and _pos with {0, 0}.
             */
            MouseEvent(Type event);
            /**
             * @brief Constructor with the event type and mouse position arguments.
             * Initialize _type with the event given and _pos with the position given.
             */
            MouseEvent(Type event, Pos pos);
            /**
             * @brief Just a destructor, nothing to see here.
             */
            ~MouseEvent();


        private:
            const Type _type;
            Pos _pos;


    };

}

#endif /* MOUSE_EVENT_HPP */
