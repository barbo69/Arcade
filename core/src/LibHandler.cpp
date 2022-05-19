/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** LibHandler
*/

#include "../include/LibHandler.hpp"
#include <dlfcn.h>
#include <unistd.h>
#include <iostream>
#include <regex>
#include <filesystem>

namespace Arcade {

    LibHandler::LibraryException::LibraryException(std::string msg):
    _msg(msg)
    {};

    LibHandler::LibraryException::~LibraryException()
    {};

    const char *LibHandler::LibraryException::what() const noexcept
    {
        return _msg.data();
    };

    LibHandler::LibHandler():
    _gameHandle(nullptr), _displayHandle(nullptr), _display(nullptr), _game(nullptr)
    {
        std::filesystem::path libsdir = "./lib";
        std::regex libraryName("arcade_(\\S+)\\.so");
        std::smatch m;

        for (const auto &it: std::filesystem::directory_iterator(std::filesystem::absolute(libsdir))) {
            std::string pathAsString = it.path();
            if (std::regex_search(pathAsString, m, libraryName)) {
                if (_validDisplays.contains(m[1])) {
                    _availableDisplays.emplace(m[1]);
                } else {
                    _availableGames.emplace(m[1]);
                }
            }
        }
        this->loadLibrary("menu");
    }

    LibHandler::~LibHandler()
    {}

    void LibHandler::loadLibrary(std::string name)
    {
        std::filesystem::path path = "lib/arcade_" + name + ".so";
        void *handle = dlopen(std::filesystem::absolute(path).c_str() , RTLD_LAZY);
        if (!handle)
            throw LibraryException(dlerror());
        unsigned char (*getLibType)() = reinterpret_cast<unsigned char (*)()>(dlsym(handle, "getLibType"));
        if (!getLibType)
            throw LibraryException(dlerror());
        if (getLibType() == 0) {
            _currentDisplay = name;
            switchDisplayLibrary(handle);
        } else {
            _currentGame = name;
            if (_display != nullptr) {
                _display->clear();
            }
            switchGameLibrary(handle);
        }
    }

    void LibHandler::switchDisplayLibrary(void *handle)
    {
        std::cout << "switching display library" << std::endl;
        if (_displayHandle) {
            std::cout << "dlclosing display handle" << std::endl;
            _display->stop();
            dlclose(_displayHandle);
        }
        _displayHandle = handle;
        IDisplay *(*getDisplayInstance)() = reinterpret_cast<IDisplay *(*)()>(dlsym(_displayHandle, "getDisplayInstance"));
        if (!getDisplayInstance)
            throw LibraryException(dlerror());
        _display = getDisplayInstance();
        _display->init();
    }

    void LibHandler::switchGameLibrary(void *handle)
    {
        std::string playerName = "";
        if (_gameHandle) {
            playerName = _game->getPlayerName();
            _game->stop();
            dlclose(_gameHandle);
        }
        _gameHandle = handle;
        IGame *(*getGameInstance)() = reinterpret_cast<IGame *(*)()>(dlsym(_gameHandle, "getGameInstance"));
        if (!getGameInstance)
            throw LibraryException(dlerror());
        _game = getGameInstance();
        _game->init();
        _game->setPlayerName(playerName);
    }

    IDisplay *LibHandler::getDisplay()
    {
        return _display;
    }

    IGame *LibHandler::getGame()
    {
        return _game;
    }

    void LibHandler::shutdown()
    {
        if (_gameHandle) {
            _game->stop();
            dlclose(_gameHandle);
        }
        if (_displayHandle) {
            _display->stop();
            dlclose(_displayHandle);
        }
    }

    void LibHandler::changeGame(char which)
    {


        if (which == 'n') {
            auto it = _availableGames.find(_currentGame);
            for (auto &it2: _availableGames) {
                std::cout << it2 << std::endl;
            }
            std::cout << *it << std::endl;
            if (std::next(it) != _availableGames.end()) {
                std::cout << "loading next game: " << *std::next(it) << std::endl;
                this->loadLibrary(*(std::next(it)));
            } else {
                std::cout << "loading next game: " << *_availableGames.begin() << std::endl;
                this->loadLibrary(*(_availableGames.begin()));
            }
        } else if (which == 'p') {
            auto it = std::find(_availableGames.rbegin(), _availableGames.rend(), _currentGame);
            if (std::next(it) != _availableGames.rend()) {
                std::cout << "loading prev game: " << *std::next(it) << std::endl;
                this->loadLibrary(*(std::prev(it)));
            } else {
                std::cout << "loading prev game: " << *_availableGames.rbegin() << std::endl;
                this->loadLibrary(*(_availableGames.rbegin()));
            }
        }

    }

    void LibHandler::changeDisplay(char which)
    {
        if (which == 'n') {
            auto it = _availableDisplays.find(_currentDisplay);
            if (std::next(it) != _availableDisplays.end()) {
                std::cout << "loading next display: " << *std::next(it) << std::endl;
                this->loadLibrary(*(std::next(it)));
            } else {
                std::cout << "loading next display: " << *_availableDisplays.begin() << std::endl;
                this->loadLibrary(*(_availableDisplays.begin()));
            }
        } else if (which == 'p') {
            auto it = std::find(_availableDisplays.rbegin(), _availableDisplays.rend(), _currentDisplay);
            if (std::next(it) != _availableDisplays.rend()) {
                std::cout << "loading prev display: " << *std::next(it) << std::endl;
                this->loadLibrary(*(std::prev(it)));
            } else {
                std::cout << "loading prev display: " << *_availableDisplays.rbegin() << std::endl;
                this->loadLibrary(*(_availableDisplays.rbegin()));
            }
        }
    }

    const std::set<std::string> &LibHandler::getValidDisplays() const
    {
        return _validDisplays;
    }
}
