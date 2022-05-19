/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <vector>
#include <memory>

#include "IComponent.hpp"
#include "IEvent.hpp"

namespace Arcade {
    /**
     * @brief This interface defines how to interact with graphic libraries.
     * It represents the IO components.
     * IDisplay's purpose is to poll events (Inputs), and to draw components on the screen / play sounds (Outputs)
     */
    class IDisplay {
        public:
            virtual ~IDisplay() = default;

            /**
             * @brief Initialize the library
             *
             */
            virtual void init() = 0;
            /**
             * @brief Stop the library
             *
             */
            virtual void stop() = 0;
            /**
             * @brief Get the Library Name
             *
             * @return std::string
             */
            virtual std::string getLibName() const = 0;
            /**
             * @brief Displays components. If Component Type is SOUND, nothing happens
             *
             * @param components
             */
            virtual void display(std::vector<std::unique_ptr<IComponent>> &components) = 0; // Display with components
            /**
             * @brief Get the Events polled by the library
             *
             * @return std::vector<std::unique_ptr<IEvent>>&
             */
            virtual std::vector<std::unique_ptr<IEvent>> &getEvents() = 0;
            /**
             * @brief Clear graphicals objects list
             * 
             */
            virtual void clear() = 0;
    };
}

#endif /* !IDISPLAY_HPP */
