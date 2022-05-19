/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextScoreNb
*/

#include "TextScoreNb.hpp"

Arcade::TextScoreNb::TextScoreNb(const std::size_t &id)
: ComponentText(id, "./games/pacman/resources/font/Gameplay", ComponentTextType::SCORE_NB)
{
    Rect rect = { 0, 0, 500, 500  };

    setX(105);
    setY(15);
    setText("0");
    setHeight(10);
    setWidth(20);
    setFontSize(20);
    setRect(rect);
}

Arcade::TextScoreNb::~TextScoreNb()
{
}
