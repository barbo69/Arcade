/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanError
*/

#include "PacmanError.hpp"

Arcade::PacmanError::PacmanError(const std::string &message)
: _message(message)
{

}

Arcade::PacmanError::~PacmanError()
{
    
}

const char *Arcade::PacmanError::what() const noexcept
{
    return _message.c_str();
}
