/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Core
*/

#include "../include/Core.hpp"
#include <iostream>
#include <filesystem>
#include <regex>

namespace Arcade
{
    Core::Core()
    {
    }

    Core::~Core()
    {
    }

    void Core::run()
    {
        EventNormalizer e;

        while (true) {
            std::vector<std::unique_ptr<Arcade::IEvent>> &events = _libHandler.getDisplay()->getEvents();
            e.normalizeEvents(events, _libHandler.getDisplay()->getLibName());
            _libHandler.getGame()->sendEvents(events);
            if (_processGameEvents() == false)
                break;
            std::vector<std::unique_ptr<Arcade::IComponent>> &components = _libHandler.getGame()->getComponents();
            _libHandler.getDisplay()->display(components);
        }
        _libHandler.shutdown();
    }

    bool Core::_processGameEvents()
    {
        IEvent *e = _libHandler.getGame()->getEvent();

        while (e != nullptr) {
            switch (e->getKey()) {
                case 'p':
                    _libHandler.changeGame('p');
                    break;
                case 'n':
                    _libHandler.changeGame('n');
                    break;
                case 'q':
                    return false;
                case 'l':
                    _libHandler.changeDisplay('p');
                    break;
                case 'm':
                    _libHandler.changeDisplay('n');
                    break;
                case 'r':
                    _libHandler.loadLibrary(e->getData());
                    break;
                case 's':
                    _libHandler.getGame()->stop();
                    _libHandler.getGame()->init();
                    break;
            }
            e = _libHandler.getGame()->getEvent();
        }
        return true;
    }

    int Core::errorHandling(const int ac, char const * const*av)
    {
        if (ac < 2) {
            std::cerr << "You must provide a graphic library to start with" << std::endl;
            return 84;
        }
        if (ac > 2) {
            std::cerr << "Only 1 argument needed" << std::endl;
            return 84;
        }
        try {
            std::regex libraryNameRegex("arcade_(\\S+)\\.so");
            std::smatch m;
            std::string libName = av[1];

            if (!std::regex_search(libName, m, libraryNameRegex)) {
                std::cerr << "Library name is not valid" << std::endl;
                return 84;
            }
            if (_libHandler.getValidDisplays().find(m[1]) == _libHandler.getValidDisplays().end()) {
                std::cerr << "Library must be a valid graphical library" << std::endl;
                return 84;
            }
            _libHandler.loadLibrary(m[1]);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
        return 0;
    }

} // namespace Arcade

