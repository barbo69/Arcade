/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextWin
*/

#include "TextWin.hpp"

Arcade::TextWin::TextWin(const std::size_t &id)
: ComponentText(id, "./games/pacman/resources/font/Gameplay", ComponentTextType::WIN)
{
    Rect rect = { 0, 0, 500, 500 };

    setX(34);
    setY(20);
    setText("You Win");
    setHeight(10);
    setWidth(30);
    setFontSize(20);
    setRect(rect);  
}

Arcade::TextWin::~TextWin()
{

}
