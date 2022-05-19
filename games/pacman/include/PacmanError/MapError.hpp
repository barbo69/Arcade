/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** MapError
*/

#ifndef MAPERROR_HPP_
#define MAPERROR_HPP_

#include "PacmanError.hpp"
#include "IComponent.hpp"

namespace Arcade {

    enum class MapErrorType {
        OPEN,
        TOOSHORT,
        TOOLONG,
        DIMENSION,
        WRONGCHARACTER,
        PLAYERNOTFOUND
    };

    class MapError : public PacmanError {
        public:
            MapError(const MapErrorType type);
            MapError(
                const MapErrorType type,
                const size_t line
            );
            ~MapError();
            


        private:
            std::string _basicErrorMessage(const MapErrorType type);
            std::string _speErrorMessage(
                const MapErrorType type,
                const size_t line
            );
    };
}

#endif /* !MAPERROR_HPP_ */
