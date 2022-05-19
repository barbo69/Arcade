/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP
#define IGAME_HPP

#include <vector>
#include <memory>
#include <string>

#include "IComponent.hpp"
#include "IEvent.hpp"

namespace Arcade {
    /**
     * @brief IGame represents a game loaded into the core.
     * Its methods allow to get game information, which can be passed down to IDisplay by the core
     */
    class IGame {
        public:
            virtual ~IGame() = default;
            /**
             * @brief initiliaze the game
             *
             */
            virtual void init() = 0;
            /**
             * @brief cleanup the game
             *
             */
            virtual void stop() = 0;
            /**
             * @brief Get the Game name
             *
             * @return std::string
             */
            virtual std::string getGameName() const = 0;
            /**
             * @brief Get the IComponents from the game
             * Their order in the vector determines in which order they are displayed.
             * @return std::vector<std::unique_ptr<IComponent>>&
             */
            virtual std::vector<std::unique_ptr<IComponent>> &getComponents() = 0;
            /**
             * @brief This function is called to send the events polled by the libs to the game.
             * You can use this function as your game entrypoint.
             * @param events 
             */
            virtual void sendEvents(std::vector<std::unique_ptr<IEvent>> &events) = 0;
            /**
             * @brief Get special events from IGame.
             * It can be used to pass back data to the arcade core, and to indicate maybe a lib change call.
             * @return IEvent* 
             */
            virtual IEvent *getEvent() = 0; // Get event, null if no event

            /**
             * @brief Set the Player Name.
             *
             * @param name 
             */
            virtual void setPlayerName(std::string const name) = 0;

            /**
             * @brief Get the Player Name
             * 
             * @return std::string
             */
            virtual std::string getPlayerName() const = 0;
    };
}

#endif /* !IGAME_HPP */
