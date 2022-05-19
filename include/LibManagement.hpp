/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** LibManagement
*/

#ifndef LIB_MANAGEMENT_HPP
#define LIB_MANAGEMENT_HPP

#include "IGame.hpp"
#include "IDisplay.hpp"

/**
 * @brief Get the type of a lib
 *
 * @return unsigned char (0 = Display | 1 = Game)
 */
extern "C" unsigned char getLibType();

/**
 * @brief create a IGame Object.
 *
 */
extern "C" Arcade::IGame *getGameInstance();

/**
 * @brief create a IDisplay Object.
 *
 */
extern "C" Arcade::IDisplay *getDisplayInstance();

#endif /* !LIB_MANEGEMENT_HPP */
