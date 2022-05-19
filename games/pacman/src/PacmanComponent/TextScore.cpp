/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** TextScore
*/

#include "TextScore.hpp"

Arcade::TextScore::TextScore(const std::size_t &id)
: ComponentText(id, "./games/pacman/resources/font/Gameplay", ComponentTextType::GAME_OVER)
{
    Rect rect = { 0, 0, 500, 500  };

    setX(105);
    setY(5);
    setText("Score:");
    setHeight(10);
    setWidth(45);
    setFontSize(20);
    setRect(rect);
}

Arcade::TextScore::~TextScore()
{
}
