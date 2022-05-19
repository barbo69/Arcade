/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** eventNormalization
*/

#include "../include/EventNormalizer.hpp"
#include "../../include/logger.h"
#include <map>

EventNormalizer::ENException::ENException(std::string msg):
_msg(msg)
{

}

EventNormalizer::ENException::~ENException()
{}

const char *EventNormalizer::ENException::what() const noexcept
{
    return _msg.data();
}


EventNormalizer::EventNormalizer()
{}

EventNormalizer::~EventNormalizer()
{}

void EventNormalizer::normalizeEvents(std::vector<std::unique_ptr<Arcade::IEvent>> &events, const std::string &libName)
{
    std::map<std::string, lib_t> libs;
    libs["sfml"] = SFML;
    libs["sdl2"] = SDL;
    libs["ncurses"] = NCURSES;

    for (auto &e: events) {
        _normalize(e, libs[libName]);
    }
}

keycode_t EventNormalizer::_findSpecialCode(keycode_t code, lib_t lib)
{
    for (int i = 0; i < NB_FUNCTION_KEYS; i++) {
        if (functionKeyEquivalents[i][lib] == code)
            return functionKeyEquivalents[i][0];
    }
    return code;
}

void EventNormalizer::_normalize(std::unique_ptr<Arcade::IEvent> &e, lib_t lib)
{
    auto key = e->getKey();

    if (lib != SFML) {

        if (key <= 'z' && key >= 'a') {
            e->setKey(key - 97);
            return;
        }
        e->setKey(_findSpecialCode(key, lib));
    }
}