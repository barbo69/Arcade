/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanAnim
*/

#include "PacmanAnim.hpp"
#include "AnimPacman.hpp"
#include "AnimRedGhost.hpp"
#include "AnimPinkGhost.hpp"
#include "AnimBlueGhost.hpp"
#include "AnimYellowGhost.hpp"

Arcade::PacmanAnim::PacmanAnim()
{   
    _currentRect = { 0, 0, 0, 0 };
    _currentAnim = PacmanAnimMove::RIGHT;
    _delay = 0;
    _lastTime = std::chrono::high_resolution_clock::now();
}

Arcade::PacmanAnim::~PacmanAnim()
{

}

void Arcade::PacmanAnim::setAnim(
    const RectList &rectList,
    const float &delay,
    const PacmanAnimMove &type
)
{
    AnimTypeRectListMap::iterator it = _map.find(type);
    RectList::const_iterator i = rectList.begin();
    Rect temp = { 0, 0, 0, 0 };

    if (it == _map.end()) {
        _map.insert(AnimTypeRectListPair(type, rectList));
    } else {
        _map.erase(it);
        _map.insert(AnimTypeRectListPair(type, rectList));
    }
    _delay = delay;
}

void Arcade::PacmanAnim::setCurrentAnim(const PacmanAnimMove &currentAnim)
{
    _currentAnim = currentAnim;
}

Arcade::PacmanAnimMove Arcade::PacmanAnim::getCurrentAnim(void) const
{
    return _currentAnim;
}

Arcade::Rect Arcade::PacmanAnim::animate()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
    std::chrono::duration<float> duration;
    AnimTypeRectListMap::iterator it;

    newTime = std::chrono::high_resolution_clock::now();
    duration = (newTime - _lastTime) * 1000;
    if (duration.count() >= _delay) {
        _lastTime = std::chrono::high_resolution_clock::now();
        it = _map.find(_currentAnim);
        if (it != _map.end())
            _changeRectPos(it->second, it->first);
    }
    return _currentRect;
}

Arcade::IPacAnimUptr Arcade::PacmanAnim::makeAnim(const PacmanAnimType &type)
{
    switch (type) {
        case PacmanAnimType::PACMAN:
            return std::make_unique<Arcade::AnimPacman>();
        case PacmanAnimType::RED_GHOST:
            return std::make_unique<Arcade::AnimRedGhost>();
        case PacmanAnimType::PINK_GHOST:
            return std::make_unique<Arcade::AnimPinkGhost>();
        case PacmanAnimType::BLUE_GHOST:
            return std::make_unique<Arcade::AnimBlueGhost>();
        case PacmanAnimType::YELLOW_GHOST:
            return std::make_unique<Arcade::AnimYellowGhost>();
    }
    return nullptr;
}

void Arcade::PacmanAnim::_changeRectPos(RectList &list, const PacmanAnimMove &type)
{
    RectList::iterator it = list.end();

    if (type == PacmanAnimMove::DEATH) {
        if (!list.empty())
            list.erase(list.begin());
    } else {
        list.splice(list.end(), list, list.begin());
    }
    if (!list.empty()) {
        _currentRect.height = list.begin()->height;
        _currentRect.width = list.begin()->width;
        _currentRect.x = list.begin()->x;
        _currentRect.y = list.begin()->y;
    }
}