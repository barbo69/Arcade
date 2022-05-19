/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** MapError
*/

#include "MapError.hpp"
    
Arcade::MapError::MapError(const MapErrorType type)
: PacmanError(_basicErrorMessage(type))
{
    
}

Arcade::MapError::MapError(
    const MapErrorType type,
    const size_t line
)
: PacmanError(_speErrorMessage(type, line + 1))
{
    
}

Arcade::MapError::~MapError()
{

}

std::string Arcade::MapError::_basicErrorMessage(const MapErrorType type)
{
    switch (type) {
        case MapErrorType::OPEN:
            return "Map can't be openned";
        case MapErrorType::DIMENSION:
            return "Pacman map need to be in 100x100 dimension";
        case MapErrorType::PLAYERNOTFOUND:
            return "Player not found in the map";

        default:
            return "Error in Map module";
    }
}

std::string Arcade::MapError::_speErrorMessage(
    const MapErrorType type,
    const size_t line
)
{
    switch (type) {
        case MapErrorType::TOOSHORT:
            return "Line " + std::to_string(line)
            + " is too short (100 char only)";
        case MapErrorType::TOOLONG:
            return "Line " + std::to_string(line) +
            " is too long (100 char only)";
        case MapErrorType::WRONGCHARACTER:
            return "Wrong character at line " + std::to_string(line);

        default:
            return "Error in Map module";
    }
}
