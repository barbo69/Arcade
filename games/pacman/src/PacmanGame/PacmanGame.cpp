/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanGame
*/

#include "PacmanGame.hpp"
#include <iostream>
#include "ComponentObject.hpp"
#include "ComponentText.hpp"
#include "PacmanScore.hpp"

Arcade::PacmanGame::PacmanGame()
: _gameName("Pacman")
{
    _status = PacmanGameStatus::START;
    _comptCompt = 0;
    _score = 0;
    _gumsCount = 0;
    _gameClock = std::chrono::high_resolution_clock::now();
    _startClock = std::chrono::high_resolution_clock::now();
    _gameDelay = 50;

}

Arcade::PacmanGame::~PacmanGame()
{

}

void Arcade::PacmanGame::init()
{
    _comptCompt = 0;
    _gumsCount = 0;
    _status = PacmanGameStatus::START;
    _gameClock = std::chrono::high_resolution_clock::now();
    _startClock = std::chrono::high_resolution_clock::now();
    _initPacman();
    _initGhosts();   
    _comptCompt = 6;
    _initScore();
    _map->computeBigPacGums(_components, _comptCompt, _gumsCount);
    _map->computeLittlePacGums(_components, _comptCompt, _gumsCount);
}

void Arcade::PacmanGame::stop()
{
    PacmanScore score;

    _components.clear();
    score.loadScores(_gameName);
    score.addScore(_playerName, static_cast<int>(_score));
    score.saveScores();
}

std::string Arcade::PacmanGame::getGameName() const
{
    return _gameName;
}

Arcade::ICompUPtrVect &Arcade::PacmanGame::getComponents()
{   
    if (_status != PacmanGameStatus::START && _checkDelay())
        _map->moveEnemies();
    _map->checkGumsHitbox(_components, _score, _gumsCount);
    for (size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getType() == IComponent::OBJECT)
            _handleObjects(_components[i]);
        if (_components[i]->getType() == IComponent::TEXT)
            _handleTexts(_components[i]);
    }
    _handleGame();
    return reinterpret_cast<ICompUPtrVect&>(_components);
}

void Arcade::PacmanGame::sendEvents(IEventUPtrVect &events)
{
    for (size_t i = 0; i < events.size(); i++) {
        if (events[i]->getKey() == 73 && _inGameOrStartCondition())
            _map->movePlayer(PacmanMap::PlayerMove::UP);
        if (events[i]->getKey() == 74 && _inGameOrStartCondition())
            _map->movePlayer(PacmanMap::PlayerMove::DOWN);
        if (events[i]->getKey() == 71 && _inGameOrStartCondition())
            _map->movePlayer(PacmanMap::PlayerMove::LEFT);
        if (events[i]->getKey() == 72 && _inGameOrStartCondition())
            _map->movePlayer(PacmanMap::PlayerMove::RIGHT);
        if (events[i]->getKey() == 58 && _gameOverOrWinCondition())
            _status = PacmanGameStatus::RESET;
        _handleCoreEvents(events[i]);
    }

}

Arcade::IEvent *Arcade::PacmanGame::getEvent()
{
    if (_event)
        delete _event;
    if (!_events.empty()) {
        _event = _events.front();
        _events.pop();
    } else {
        _event = nullptr;
    }
    return _event;
}

void Arcade::PacmanGame::_managePlayerMove(
    const PacmanMap::PlayerMove &move,
    const IPacCompUPtr &pacman
)
{
   if (move == PacmanMap::PlayerMove::LEFT && _inGameOrStartCondition()) {
        pacman->setObjectCurrentAnimation(PacmanAnimMove::LEFT);
        _map->movePlayer(PacmanMap::PlayerMove::LEFT);
    }
    if (move == PacmanMap::PlayerMove::RIGHT && _inGameOrStartCondition()) {
        pacman->setObjectCurrentAnimation(PacmanAnimMove::RIGHT);
        _map->movePlayer(PacmanMap::PlayerMove::RIGHT);
    }
    if (move == PacmanMap::PlayerMove::UP && _inGameOrStartCondition()) {
        pacman->setObjectCurrentAnimation(PacmanAnimMove::UP);
        _map->movePlayer(PacmanMap::PlayerMove::UP);
    }
    if (move == PacmanMap::PlayerMove::DOWN && _inGameOrStartCondition()) {
        pacman->setObjectCurrentAnimation(PacmanAnimMove::DOWN);
        _map->movePlayer(PacmanMap::PlayerMove::DOWN);
    }
    if (move == PacmanMap::PlayerMove::DEATH && _inGameOrStartCondition()) {
        pacman->setObjectCurrentAnimation(PacmanAnimMove::DEATH);
        _gameOver();
    }
}


void Arcade::PacmanGame::setPlayerName(std::string const playerName)
{
    _playerName = playerName;
}

std::string Arcade::PacmanGame::getPlayerName() const
{
    return _playerName;
}

void Arcade::PacmanGame::_initPacman()
{
    _map = std::make_unique<PacmanMap>();
    _components.push_back(ComponentObject::makeObject(5,
    (PacmanMap::Pos) { 0, 0 }, ComponentObjectType::MAP));
    _components.push_back(ComponentObject::makeObject(4,
    _map->getPlayerPos(), ComponentObjectType::PACMAN));
}

void Arcade::PacmanGame::_initGhosts()
{
    _components.push_back(ComponentObject::makeObject(0,
    _map->getEnemyPos(0), ComponentObjectType::RED_GHOST));
    _components.push_back(ComponentObject::makeObject(1,
    _map->getEnemyPos(1), ComponentObjectType::PINK_GHOST));
    _components.push_back(ComponentObject::makeObject(2,
    _map->getEnemyPos(2), ComponentObjectType::BLUE_GHOST));
    _components.push_back(ComponentObject::makeObject(3,
    _map->getEnemyPos(3), ComponentObjectType::YELLOW_GHOST));
}

void Arcade::PacmanGame::_initScore()
{
    PacmanScore score;

    _components.push_back(ComponentText::makeText(_comptCompt,
    ComponentTextType::SCORE));
    _comptCompt++;
    _components.push_back(ComponentText::makeText(_comptCompt,
    ComponentTextType::SCORE_NB));
    _comptCompt++;
    score.loadScores(_gameName);
    _score = static_cast<size_t>(score.getScore(_playerName));
}

void Arcade::PacmanGame::_handleGame()
{
    if (_status == PacmanGameStatus::IN_GAME && _gumsCount == 0)
        _win();
    if (_status == PacmanGameStatus::START)
        _start();
    if (_status == PacmanGameStatus::RESET)
        _reset();
    _resetDelay();
}

void Arcade::PacmanGame::_handleObjects(IPacCompUPtr &component)
{
    component->animateObject();
    if (component->getId() == 4 && _inGameOrStartCondition()) {
        if (_checkDelay()) {
            component->setX(_map->getPlayerPos().x);
            component->setY(_map->getPlayerPos().y);
            _managePlayerMove(_map->getPlayerMove(), component);
        }
    }
    if (component->getId() >= 0 && component->getId() <= 3 
        && _inGameOrStartCondition()) {
        if (_checkDelay()) {
            component->setX(_map->getEnemyPos(component->getId()).x);
            component->setY(_map->getEnemyPos(component->getId()).y);
            _manageEnemiesMove(_map->getEnemyMove(component->getId()),
            component);
        }
    }
}

void Arcade::PacmanGame::_handleTexts(IPacCompUPtr &component)
{
    _refreshScore(component);
}

void Arcade::PacmanGame::_handleCoreEvents(const IEventUPtr &event)
{
    if (event->getKey() == 15)
        _events.push(new PacmanEvent('p'));
    if (event->getKey() == 13)
        _events.push(new PacmanEvent('n'));
    if (event->getKey() == 11)
        _events.push(new PacmanEvent('l'));
    if (event->getKey() == 12)
        _events.push(new PacmanEvent('m'));
    if (event->getKey() == 17)
        _events.push(new PacmanEvent('r'));
    if (event->getKey() == 36)
        _events.push(new PacmanEvent('q'));
    if (event->getKey() == 18)
        _events.push(new PacmanEvent('s'));
}

void Arcade::PacmanGame::_manageEnemiesMove(
    const PacmanMap::PlayerMove &move,
    const IPacCompUPtr &enemy
)
{
    if (move == PacmanMap::PlayerMove::LEFT)
        enemy->setObjectCurrentAnimation(PacmanAnimMove::LEFT);
    if (move == PacmanMap::PlayerMove::RIGHT)
        enemy->setObjectCurrentAnimation(PacmanAnimMove::RIGHT);
    if (move == PacmanMap::PlayerMove::UP)
        enemy->setObjectCurrentAnimation(PacmanAnimMove::UP);
    if (move == PacmanMap::PlayerMove::DOWN)
        enemy->setObjectCurrentAnimation(PacmanAnimMove::DOWN);
    if (move == PacmanMap::PlayerMove::WEEKNESS)
        enemy->setObjectCurrentAnimation(PacmanAnimMove::WEAKNESS);
    if (move == PacmanMap::PlayerMove::DEATH)
        enemy->setObjectCurrentAnimation(PacmanAnimMove::ENEMY_DEATH);
}

void Arcade::PacmanGame::_refreshScore(IPacCompUPtr &component)
{
    if (component->getComponentTextType() == ComponentTextType::SCORE_NB)
        component->setText(std::to_string(_score));
}

bool Arcade::PacmanGame::_checkDelay()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
    std::chrono::duration<float> duration;

    newTime = std::chrono::high_resolution_clock::now();
    duration = (newTime - _gameClock) * 1000;
    if (duration.count() >= _gameDelay) {
        return true;
    }
    return false;
}

void Arcade::PacmanGame::_resetDelay()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
    std::chrono::duration<float> duration;

    newTime = std::chrono::high_resolution_clock::now();
    duration = (newTime - _gameClock) * 1000;
    if (duration.count() >= _gameDelay) {
        _gameClock = newTime;
    }
    return;
}

void Arcade::PacmanGame::_gameOver()
{
    IPacCompUPtrVect::iterator it = _components.begin();

    _status = PacmanGameStatus::GAME_OVER;
    while (it != _components.end()) {
        if (it->operator->()->getId() != 4 && it->operator->()->getId() != 5 &&
            it->operator->()->getId() != 6 && it->operator->()->getId() != 7) {
            it = _components.erase(it);
        } else {
            it++;
        }
    }
    _components.push_back(ComponentText::makeText(_comptCompt,
    ComponentTextType::GAME_OVER));
    _comptCompt++;
    _components.push_back(ComponentText::makeText(_comptCompt,
    ComponentTextType::TEXT_RESET));
    _comptCompt++;
}

void Arcade::PacmanGame::_win()
{
    IPacCompUPtrVect::iterator it = _components.begin();

    _status = PacmanGameStatus::WIN;
    while (it != _components.end()) {
        if (it->operator->()->getId() != 4 && it->operator->()->getId() != 5 &&
            it->operator->()->getId() != 6 && it->operator->()->getId() != 7) {
            it = _components.erase(it);
        } else {
            it++;
        }
    }
    _components.push_back(ComponentText::makeText(_comptCompt,
    ComponentTextType::WIN));
    _comptCompt++;
    _components.push_back(ComponentText::makeText(_comptCompt,
    ComponentTextType::TEXT_RESET));
    _comptCompt++;
}

void Arcade::PacmanGame::_start()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
    std::chrono::duration<float> duration;

    newTime = std::chrono::high_resolution_clock::now();
    duration = (newTime - _startClock);
    if (duration.count() >= 10) {
        _status = PacmanGameStatus::IN_GAME;
        _startClock = newTime;
    }
}

void Arcade::PacmanGame::_reset()
{   
    PacmanScore score;

    _map.reset();
    _components.clear();
    score.loadScores(_gameName);
    if (_status == PacmanGameStatus::GAME_OVER) {
        _score = 0;
        score.addScore(_playerName, 0);
        score.saveScores();
        _gameDelay = 50;
    }
    if (_status == PacmanGameStatus::WIN) {
        score.addScore(_playerName, static_cast<int>(_score));
        _gameDelay = _gameDelay / 2;
        score.saveScores();
    }
    init();
}

bool Arcade::PacmanGame::_inGameOrStartCondition()
{
    return _status == PacmanGameStatus::IN_GAME
    || _status == PacmanGameStatus::START;
}

bool Arcade::PacmanGame::_gameOverOrWinCondition()
{
    return _status == PacmanGameStatus::GAME_OVER
    || _status == PacmanGameStatus::WIN;
}