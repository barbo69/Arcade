/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** ArcadeSfml
*/

#include "ArcadeSfml.hpp"
#include "SfmlEvent.hpp"
#include "SfmlData.hpp"
#include "SfmlComponent.hpp"
#include <iostream>
#include <filesystem>

Arcade::ArcadeSfml::ArcadeSfml() : _name("SFML")
{

}

Arcade::ArcadeSfml::~ArcadeSfml()
{

}

void Arcade::ArcadeSfml::init()
{   
    std::filesystem::path sideLeft;
    std::filesystem::path sideRight;

    _window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32),
    "Arcade Sfml");
    _window.setFramerateLimit(30);
    sideLeft = "graphics/sfml/resources/ArcadeSideLeft";
    sideRight = "graphics/sfml/resources/ArcadeSideRight";
    _basicData.push_back(SfmlData::SfmlDataFactory(
    std::filesystem::absolute(sideLeft),IComponent::OBJECT));
    _basicData.push_back(SfmlData::SfmlDataFactory(
    std::filesystem::absolute(sideRight),IComponent::OBJECT)); 
    _basicComponents.push_back(SfmlComponent::sfmlComponentFactory(
    0, IComponent::OBJECT, _basicData[0]));
    _basicComponents.push_back(SfmlComponent::sfmlComponentFactory(
    0, IComponent::OBJECT, _basicData[1]));
    _basicComponents[0]->setPos(0, 0);
    _basicComponents[1]->setPos(GAME_BORDER_X + (100 * GRID_PIXEL_SIZE), 0);
    _basicComponents[0]->setWidth(46);
    _basicComponents[1]->setWidth(46); 
}

void Arcade::ArcadeSfml::stop()
{
    _events.clear();
    _window.close();
}

std::string Arcade::ArcadeSfml::getLibName() const
{
    return _name;
}

void Arcade::ArcadeSfml::display(ICompUPtrVect &components)
{   
    Arcade::ISfmlCompUPtrMap::iterator it;

    _checkData(components);
    // _cleanData(components);
    _window.clear();
    for (size_t i = 0; i < _basicComponents.size(); i++) {
        if (_basicComponents[i]->getType() != IComponent::SOUND)
            _basicComponents[i]->draw(_window);
    }
    for (size_t i = 0; i < components.size(); i++) {
        it = _components.find(components[i]->getId());
        if (it == _components.end())
            throw std::runtime_error("Unknown component");
        if (it->second->getType() != IComponent::SOUND)
            it->second->draw(_window);
    }
    _window.display();
    _components.clear();
    
}

Arcade::IEventUPtrVect &Arcade::ArcadeSfml::getEvents()
{   
    sf::Event event;

    _events.clear();
    while (_window.pollEvent(event)) {
        if (event.KeyPressed == event.type)
            _events.push_back(std::make_unique<SfmlEvent>(event, _window));
    }
    return _events;
}

void Arcade::ArcadeSfml::_checkData(ICompUPtrVect &components) 
{
    std::string filePath = "";
    Arcade::ISfmlCompUPtrMap::iterator it;

    for (size_t x = 0; x < components.size(); x++) {
        filePath = components[x]->getFile();
        if (_data.find(filePath) == _data.end()) {
            _data.insert(StrUPtrISfmlDataPair(filePath,
            Arcade::SfmlData::SfmlDataFactory(filePath,
            components[x]->getType())));
        }
        if (_components.find(components[x]->getId()) == _components.end()) {
            _components.insert(SizeUPtrISfmlCompPair(components[x]->getId(), 
            SfmlComponent::sfmlComponentFactory(components[x]->getId(),
            components[x]->getType(), _data.find(filePath)->second)));
        }
        _updateData(components[x]);
    }
}

void Arcade::ArcadeSfml::_updateData(std::unique_ptr<IComponent> &component) 
{
    Arcade::ISfmlCompUPtrMap::iterator it;

    it = _components.find(component->getId());
    if (it == _components.end())
        throw std::runtime_error("Unknown component");
    if (it->second->getType() == IComponent::TEXT) {
        it->second->setText(component->getText());
        it->second->setPos(GAME_BORDER_X + (component->getX() *
        GRID_PIXEL_SIZE), component->getY() * GRID_PIXEL_SIZE);
        it->second->setFontSize(component->getFontSize());
    }
    if (it->second->getType() == IComponent::OBJECT) {
        it->second->setRect(component->getRect());
        it->second->setPos(GAME_BORDER_X + (component->getX() *
        GRID_PIXEL_SIZE), component->getY() * GRID_PIXEL_SIZE);
        it->second->setWidth(component->getWidth());
        it->second->setHeight(component->getHeight());
    }
    it->second->setUse(true);
}

void Arcade::ArcadeSfml::_cleanData(ICompUPtrVect &components) 
{
    Arcade::ISfmlCompUPtrMap::iterator it = _components.begin();
    Arcade::ISfmlCompUPtrMap::iterator temp;

    while (it != _components.end()) {
        if (it->second->isUsed()) {
            it->second->setUse(false);
            it++;
        } else {
            temp = it;
            it++; 
            _components.erase(temp->first);
        }
    }
}

void Arcade::ArcadeSfml::clear()
{
    std::filesystem::path sideLeft;
    std::filesystem::path sideRight;

    _events.clear();
    _data.clear();
    _components.clear();
    _basicComponents.clear();
    _basicData.clear();
    sideLeft = "graphics/sfml/resources/ArcadeSideLeft";
    sideRight = "graphics/sfml/resources/ArcadeSideRight";
    _basicData.push_back(SfmlData::SfmlDataFactory(
    std::filesystem::absolute(sideLeft),IComponent::OBJECT));
    _basicData.push_back(SfmlData::SfmlDataFactory(
    std::filesystem::absolute(sideRight),IComponent::OBJECT)); 
    _basicComponents.push_back(SfmlComponent::sfmlComponentFactory(
    0, IComponent::OBJECT, _basicData[0]));
    _basicComponents.push_back(SfmlComponent::sfmlComponentFactory(
    0, IComponent::OBJECT, _basicData[1]));
    _basicComponents[0]->setPos(0, 0);
    _basicComponents[1]->setPos(GAME_BORDER_X + (100 * GRID_PIXEL_SIZE), 0);
    _basicComponents[0]->setWidth(46);
    _basicComponents[1]->setWidth(46);
}
