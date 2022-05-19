/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IEvent
*/

#ifndef IEVENT_HPP
#define IEVENT_HPP

#include <string>

namespace Arcade {

    /**
     * @brief Used for mouse position
     *
     */
    struct Pos {
        int x;
        int y;
    };
    /**
     * @brief Represents an event polled by the graphic libraries.
     *
     */
    class IEvent {
        public:
            virtual ~IEvent() = default;

            /**
             * @brief Get the Key value of the event
             *
             * @return std::size_t
             */
            virtual std::size_t getKey() const = 0;
            /**
             * @brief Set the Key value of the event. This is only to be used by the core, to uniformize
             * the value between different libraries.
             * @param key
             * @return void
             */
            virtual void setKey(std::size_t const key) = 0;
            /**
             * @brief Get the Mouse Position
             * Position is expressed in the Pos structure {x, y}
             * @return Pos
             */
            virtual Pos getMousePos() const = 0;
            /**
             * @brief Get Data from Event
             * 
             * @return std::string 
             */
            virtual std::string getData() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP */
