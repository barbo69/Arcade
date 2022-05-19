/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Display
*/

#include "Display.hpp"
#include "Event.hpp"

#include <filesystem>
#include <iostream>

Display::DisplayException::DisplayException(std::string msg):
_msg(msg)
{}

Display::DisplayException::~DisplayException()
{}

const char *Display::DisplayException::what() const noexcept
{
    return _msg.c_str();
}


Display::Display():
_name("sdl2")
{}

Display::~Display()
{}

void Display::init()
{
    int windowFlags = 0;
    int rendererFlags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw DisplayException(SDL_GetError());
    if (IMG_Init(IMG_INIT_PNG) == -1) {
        throw DisplayException(IMG_GetError());
    }
    if(TTF_Init() == -1) {
        throw DisplayException(TTF_GetError());
    }
    _window = SDL_CreateWindow("Arcade - SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if (!_window)
        throw DisplayException(SDL_GetError());
    _renderer = SDL_CreateRenderer(_window, -1, rendererFlags);
    if (!_renderer)
        throw DisplayException(SDL_GetError());
    SDL_Surface *leftSide, *rightSide;
    leftSide = IMG_Load(std::filesystem::absolute("graphics/sdl2/resources/ArcadeSideLeft.png").c_str());
    rightSide = IMG_Load(std::filesystem::absolute("graphics/sdl2/resources/ArcadeSideRight.png").c_str());
    _leftSideBar = SDL_CreateTextureFromSurface(_renderer, leftSide);
    _rightSideBar = SDL_CreateTextureFromSurface(_renderer, rightSide);
    SDL_FreeSurface(leftSide);
    SDL_FreeSurface(rightSide);
}

void Display::stop()
{
    clear();
    SDL_DestroyTexture(_leftSideBar);
    SDL_DestroyTexture(_rightSideBar);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

std::string Display::getLibName() const
{
    return _name;
}

std::vector<std::unique_ptr<Arcade::IEvent>> & Display::getEvents()
{
    SDL_Event e;

    _events.clear();
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            _events.push_back(std::make_unique<Event>(27));
        else if (e.type == SDL_KEYDOWN) {
            _events.push_back(std::make_unique<Event>(e.key.keysym.sym)); // maybe use e.key.keysym.scancode
        }
        // else if (e.type = SDL_MOUSEMOTION)
        //     _events.push_back(std::make_unique<Event>(0, e.motion.x, e.motion.y));
        // else if (e.type = SDL_MOUSEBUTTONDOWN)
        //     _events.push_back(std::make_unique<Event>(e.button.button, e.button.x, e.button.y));
    }
    return _events;
}

void Display::display(std::vector<std::unique_ptr<Arcade::IComponent>> &components)
{
    SDL_RenderClear(_renderer);
    _cacheLoadComponents(components);
    _updateTextComponents(components);
    _renderCopy(components);
    SDL_RenderPresent(_renderer);
    SDL_Delay(100);
}

void Display::_updateTextComponents(std::vector<std::unique_ptr<Arcade::IComponent>> &components)
{
    for (auto &it: components) {
        if (it->getType() == Arcade::IComponent::TEXT) {
            std::string fileAndSize = it->getFile() + ".ttf#" + std::to_string(it->getFontSize());
            SDL_Color color = { 255, 255, 255, 255 };
            SDL_Surface *tmp = TTF_RenderText_Blended(_fonts[fileAndSize], it->getText().c_str(), color);
            _text[it->getId()] = SDL_CreateTextureFromSurface(_renderer, tmp);
            SDL_FreeSurface(tmp);
        }
    }
}


void Display::_cacheLoadComponents(std::vector<std::unique_ptr<Arcade::IComponent>> &components)
{
    for (auto &it: components) {
        if (_componentCache.find(it->getId()) == _componentCache.end()) {
            _componentCache[it->getId()] = it->getFile();
            _loadResource(it);
        }
    }
}

void Display::_renderSides()
{
    SDL_Rect srcRect {.x=0, .y=0, .w = GAME_BORDER_X, .h=SCREEN_HEIGHT};
    SDL_Rect destRect {.x = 0, .y = 0, .w = GAME_BORDER_X, .h = SCREEN_HEIGHT};
    SDL_RenderCopy(_renderer, _leftSideBar, &srcRect, &destRect);
    destRect.x = SCREEN_WIDTH - GAME_BORDER_X;
    SDL_RenderCopy(_renderer, _rightSideBar, &srcRect, &destRect);
}

void Display::_renderCopyObject(std::unique_ptr<Arcade::IComponent> &object)
{
    Arcade::Rect rect = object->getRect();
    SDL_Rect srcRect {
        .x = rect.x,
        .y = rect.y,
        .w = rect.width,
        .h = rect.height
    };
    SDL_Rect destRect {
        .x = Display::calculateXPosition(object->getX()),
        .y = Display::calculateYPosition(object->getY()),
        .w = Display::calculateTextureSize(object->getWidth()),
        .h = Display::calculateTextureSize(object->getHeight())
    };
    SDL_RenderCopy(_renderer, _textures[object->getFile()], &srcRect, &destRect);
}

void Display::_renderCopyText(std::unique_ptr<Arcade::IComponent> &text)
{
    Arcade::Rect rect = text->getRect();
    SDL_Rect srcRect {
        .x = rect.x,
        .y = rect.y,
        .w = rect.width,
        .h = rect.height
    };
    SDL_Rect destRect {
        .x = Display::calculateXPosition(text->getX()),
        .y = Display::calculateYPosition(text->getY()),
        .w = Display::calculateTextureSize(text->getWidth()),
        .h = Display::calculateTextureSize(text->getHeight())
    };
    SDL_RenderCopy(_renderer, _text[text->getId()], &srcRect, &destRect);
}

void Display::_renderCopy(std::vector<std::unique_ptr<Arcade::IComponent>> &components)
{
    _renderSides();
    for (auto &it: components) {
        if (it->getType() == Arcade::IComponent::OBJECT) {
            _renderCopyObject(it);
        } else if (it->getType() == Arcade::IComponent::TEXT) {
            _renderCopyText(it);
        }
    }
}


void Display::_loadObject(std::unique_ptr<Arcade::IComponent> &component)
{
    std::string file = component->getFile() + ".png";
    if (_textures.find(file) == _textures.end()) {
        SDL_Surface *tmp = IMG_Load(file.c_str());
        _textures[component->getFile()] = SDL_CreateTextureFromSurface(_renderer, tmp);
        SDL_FreeSurface(tmp);
    }
}

void Display::_loadFont(std::unique_ptr<Arcade::IComponent> &component)
{
    std::string file = component->getFile() + ".ttf";
    std::string fileAndSize = file + "#" + std::to_string(component->getFontSize());
    if (_fonts.find(fileAndSize) == _fonts.end()) {
        TTF_Font *f = TTF_OpenFont(file.c_str(), component->getFontSize());
        _fonts[fileAndSize] = f;
        if (!f) {
            std::cout << TTF_GetError() << std::endl;
        }
        std::cout << TTF_GetError() << std::endl;
    }
}

void Display::_loadResource(std::unique_ptr<Arcade::IComponent> &component)
{
    Arcade::IComponent::Type type = component->getType();
    if (type == Arcade::IComponent::OBJECT) {
        _loadObject(component);
    } else if (type == Arcade::IComponent::TEXT) {
        _loadFont(component);
    }
}

int Display::calculateXPosition(int x)
{
    return GAME_BORDER_X + (x * GRID_PIXEL_SIZE);
}

int Display::calculateYPosition(int y)
{
    return y * GRID_PIXEL_SIZE;
}

int Display::calculateTextureSize(int sideSize)
{
    return sideSize * GRID_PIXEL_SIZE;
}

void Display::clear()
{
    _events.clear();
    _componentCache.clear();
    _componentCache.clear();
    for (auto it: _textures)
        SDL_DestroyTexture(it.second);
    _textures.clear();
    for (auto it: _text)
        SDL_DestroyTexture(it.second);
    _text.clear();
    for (auto it: _fonts)
        TTF_CloseFont(it.second);
    _fonts.clear();
}
