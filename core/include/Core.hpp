/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../include/LibHandler.hpp"
#include "../include/EventNormalizer.hpp"

namespace Arcade {
    class Core {
        public:
            Core();
            ~Core();
            int errorHandling(const int ac, char const * const *av);
            void run();
        protected:
        private:
            Arcade::LibHandler _libHandler;
            bool _processGameEvents();
    };
}

#endif /* !CORE_HPP_ */
