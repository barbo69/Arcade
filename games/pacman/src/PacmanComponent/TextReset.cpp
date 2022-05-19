/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextReset
*/

#include "TextReset.hpp"

Arcade::TextReset::TextReset(const std::size_t &id)
: ComponentText(id, "./games/pacman/resources/font/Gameplay", ComponentTextType::TEXT_RESET)
{
    Rect rect = { 0, 0, 500, 500  };

    setX(12);
    setY(35);
    setText("Press enter to restart");
    setHeight(10);
    setWidth(80);
    setFontSize(15);
    setRect(rect);
}

Arcade::TextReset::~TextReset()
{

}
