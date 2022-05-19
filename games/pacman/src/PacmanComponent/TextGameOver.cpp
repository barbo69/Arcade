/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextGameOver
*/

#include "TextGameOver.hpp"

Arcade::TextGameOver::TextGameOver(const std::size_t &id)
: ComponentText(id, "./games/pacman/resources/font/Gameplay", ComponentTextType::GAME_OVER)
{
    Rect rect = { 0, 0, 500, 500  };

    setX(28);
    setY(20);
    setText("Game over");
    setHeight(10);
    setWidth(45);
    setFontSize(20);
    setRect(rect);
}

Arcade::TextGameOver::~TextGameOver()
{

}
