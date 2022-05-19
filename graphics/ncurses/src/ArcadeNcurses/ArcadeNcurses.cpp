/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeNcurses
*/

#include "ArcadeNcurses.hpp"
#include "NcursesEvent.hpp"
#include <fstream>
#include <sstream>

Arcade::ArcadeNcurses::ArcadeNcurses() : _name("ncurses")
{
}

Arcade::ArcadeNcurses::~ArcadeNcurses()
{
}


void Arcade::ArcadeNcurses::init()
{
    mmask_t mouse_events = BUTTON1_CLICKED | BUTTON3_CLICKED;

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    mousemask(mouse_events, NULL);
    mouseinterval(250);
    curs_set(0);
}

void Arcade::ArcadeNcurses::stop()
{
    nocbreak();
    nodelay(stdscr, false);
    keypad(stdscr, false);
    curs_set(1);
    clear();
    endwin();
}

std::string Arcade::ArcadeNcurses::getLibName() const
{
    return _name;
}

void Arcade::ArcadeNcurses::display(ICompUPtrVect &components)
{
    std::string line;
    std::istringstream s;
    std::ifstream f;
    int y;

    clear();
    for (size_t i = 0; i < components.size(); i++) {
        switch (components[i]->getType()) {
            case IComponent::Type::TEXT:
                s = std::istringstream(components[i]->getText());
                for (size_t j = components[i]->getY() / 2; getline(s, line); j++)
                    mvaddstr(j, (COLS - 80) / 2 + components[i]->getX() * 0.8, line.c_str());
            case IComponent::Type::OBJECT:
                f = std::ifstream(components[i]->getFile() + ".txt");
                y = components[i]->getY() / 2;
                for (size_t j = y; getline(f, line); j++)
                    mvaddstr(j, (COLS - 80) / 2 + components[i]->getX() * 0.8, line.c_str());
            case IComponent::Type::SOUND:
                break;
        }
    }
    refresh();
}

Arcade::IEventUPtrVect &Arcade::ArcadeNcurses::getEvents()
{
    int key = getch();

    _events.clear();
    while (key != -1) {
        _events.push_back(std::make_unique<NcursesEvent>(key));
        key = getch();
    }
    return _events;
}

void Arcade::ArcadeNcurses::clear()
{
    erase();
}