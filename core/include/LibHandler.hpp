/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibHandler
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include <string>
#include <exception>
#include <memory>
#include <set>
#include "../../include/LibManagement.hpp"

namespace Arcade {
    /**
     * @brief Encapsulates calls to dlopen, dlsym, dlerror and dlclose.
     * Use it to automatically handle library changes
     */
    class LibHandler {
        public:
            /**
             * @brief Used to throw errors with lib handling
             *
             */
            class LibraryException: public std::exception {
                public:
                    LibraryException(std::string msg);
                    ~LibraryException();
                    const char *what() const noexcept override;
                private:
                    const std::string _msg;
            };
            LibHandler();
            ~LibHandler();

            /**
             * @brief Load a library (game | display)
             * This automatically handles switches if a library is already loaded
             * @param name
             */
            void loadLibrary(std::string name);

            /**
             * @brief Returns and instance of IDisplay.
             * Use it throughout the core loop to interact with it.
             * @return std::shared_ptr<IDisplay>
             */

            IDisplay *getDisplay();


            /**
             * @brief Returns and instance of IGame.
             * Use it throughout the core loop to interact with it
             * @return std::shared_ptr<IGame>
             */
            IGame *getGame();

            void changeGame(char which); // p = previous, n = next
            void changeDisplay(char which);
            void shutdown();
            const std::set<std::string> &getValidDisplays() const;
        protected:
        private:
            void *_gameHandle;
            void *_displayHandle;
            IDisplay *_display;
            IGame *_game;
            std::set<std::string> _validDisplays {"sdl2", "ncurses", "sfml"};
            std::set<std::string> _availableDisplays;
            std::set<std::string> _availableGames;
            std::string _currentGame;
            std::string _currentDisplay;
            void switchGameLibrary(void *handle);
            void switchDisplayLibrary(void *handle);
    };
}


#endif /* !LIBLOADER_HPP_ */
