/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ComponentError
*/

#include "ComponentError.hpp"

Arcade::ComponentError::ComponentError(const ComponentErrorType type)
: PacmanError(_basicErrorMessage(type))
{

}

Arcade::ComponentError::~ComponentError()
{

}

std::string Arcade::ComponentError::_basicErrorMessage(const ComponentErrorType type)
{
    switch (type) {
        case ComponentErrorType::BAD_USAGE:
            return "Error: Bad usage of component class";

        default:
            return "Error in Component module";
    }
}
