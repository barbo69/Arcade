/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanMap
*/

#include "PacmanMap.hpp"
#include "ComponentObject.hpp"
#include "MapError.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

Arcade::PacmanMap::PacmanMap()
{
    std::filesystem::path path = "games/pacman/resources/map/map.txt";
    _openFile(std::filesystem::absolute(path));
    _checkMap();
    _loadMap();
    _refreshPlayerPos();
    _move = PlayerMove::RIGHT;
    for (int i = 0; i < 4; i++) {
        _enemiesPos[i] = { 0, 0 };
        _enemiesMove[i] = PlayerMove::RIGHT;
        _enemiesClock[i] = std::chrono::high_resolution_clock::now();
    }
    _weaknessClock = std::chrono::high_resolution_clock::now();
    _refreshEnemiesPos();
}

Arcade::PacmanMap::~PacmanMap() 
{

}

Arcade::PacmanMap::Pos Arcade::PacmanMap::getPlayerPos() const
{
    Pos playerPos;

    playerPos.x = static_cast<int>(_playerPos.x);
    playerPos.y = static_cast<int>(_playerPos.y);
    return playerPos;
}

Arcade::PacmanMap::Pos Arcade::PacmanMap::getEnemyPos(const size_t &id) const
{
    Pos enemyPos = { 0, 0 };

    if (id > 4)
        return enemyPos;
    enemyPos.x = static_cast<int>(_enemiesPos[id].x);
    enemyPos.y = static_cast<int>(_enemiesPos[id].y);
    return enemyPos;
}

bool Arcade::PacmanMap::movePlayer(const PlayerMove &move)
{   
    if (move == PlayerMove::LEFT && _playerPos.x > 1) {
        if (_map[_playerPos.y][_playerPos.x - 1] != '#')
            return _computeMove(_playerPos.x - 1, _playerPos.y, move);
    }
    if (move == PlayerMove::RIGHT && _playerPos.x < 94) {
        if (_map[_playerPos.y][_playerPos.x + 4] != '#')
            return _computeMove(_playerPos.x + 1, _playerPos.y, move);
    }
    if (move == PlayerMove::UP && _playerPos.y > 1) {
        if (_map[_playerPos.y - 1][_playerPos.x] != '#')
            return _computeMove(_playerPos.x, _playerPos.y - 1, move);
    } 
    if (move == PlayerMove::DOWN && _playerPos.y < 94) {
        if (_map[_playerPos.y + 4][_playerPos.x] != '#')
            return _computeMove(_playerPos.x, _playerPos.y + 1, move);
    }
    return _manageMapBorder(move);
}

void Arcade::PacmanMap::moveEnemies()
{   
    SPos direction[4];
    size_t bestPos = 0;

    for (size_t i = 0; i < 4; i++) {
        direction[0] = { _enemiesPos[i].x - 1, _enemiesPos[i].y };
        direction[1] = { _enemiesPos[i].x + 1 , _enemiesPos[i].y };
        direction[2] = { _enemiesPos[i].x , _enemiesPos[i].y - 1 };
        direction[3] = { _enemiesPos[i].x , _enemiesPos[i].y + 1 };
        if (_checkIfInBox(_enemiesPos[i]) && !_checkEnemyDeath(i)) {   
            bestPos = _computeEnemyMove(_enemiesPos[i], direction, { 50, 39 });
            _setNewEnemiesPos(direction[bestPos], bestPos, _enemiesPos[i], i);
            continue;
        }
        if (!_checkEnemyDeath(i)) {
            bestPos = _computeEnemyMove(_enemiesPos[i], direction, _playerPos);
            _setNewEnemiesPos(direction[bestPos], bestPos, _enemiesPos[i], i);
        }
    }
    _refreshEnemiesPos();
    _handleWeekness();
    _handleEnemyDeath();
}

Arcade::PacmanMap::PlayerMove Arcade::PacmanMap::getPlayerMove() const
{
    return _move;
}

Arcade::PacmanMap::PlayerMove Arcade::PacmanMap::getEnemyMove(const size_t &id) const
{
    Pos enemyPos = { 0, 0 };

    if (id > 4)
        return PlayerMove::RIGHT;
    return _enemiesMove[id];
}

void Arcade::PacmanMap::computeBigPacGums(
    IPacCompUPtrVect &components,
    size_t &compCompt,
    size_t &gumsCount
)
{
    for (size_t y = 0; y < _map.size(); y++) {
        for (size_t x = 0; x < _map[y].size(); x++) {
            if (_map[y][x] == 'G') {
                components.push_back(ComponentObject::makeObject(compCompt,
                { static_cast<int>(x), static_cast<int>(y) },
                ComponentObjectType::BIG_PAC_GUM));
                compCompt++;
                gumsCount++;
            }
        }
    }
}

void Arcade::PacmanMap::checkGumsHitbox(
    IPacCompUPtrVect &components,
    size_t &score,
    size_t &gumsCount
)
{
    IPacCompUPtrVect::iterator it = components.begin();

    while (it != components.end()) {
        if (it->operator->()->getType() == IComponent::OBJECT) {
            _checkHitbox(components, it, score, gumsCount);
        } else {
            it++;   
        }
    }
}

void Arcade::PacmanMap::computeLittlePacGums(
    IPacCompUPtrVect &components,
    size_t &compCompt,
    size_t &gumsCount
)
{

    for (size_t y = 0; y < _map.size(); y++) {
        for (size_t x = 0; x < _map[y].size(); x++) {
            if (_map[y][x] == 'L') {
                components.push_back(ComponentObject::makeObject(compCompt,
                { static_cast<int>(x), static_cast<int>(y) },
                ComponentObjectType::LIT_PAC_GUM));
                compCompt++;
                gumsCount++;
            }
        }
    }
}

void Arcade::PacmanMap::_openFile(const std::filesystem::path &filePath)
{
    std::ifstream isOpen(filePath, std::ios_base::ate);
    std::streamsize size;
    char *buffer = NULL;

    if (isOpen.is_open()) {
        size = isOpen.tellg();
        if (size >= 9223372036854775807)
            throw MapError(MapErrorType::OPEN);
        isOpen.seekg(0);
        buffer = new char[size + 1];
        buffer[size] = '\0';
        isOpen.read(buffer, size);
        isOpen.close();
        _fileBuffer = buffer;
        delete[] buffer;
        return;
    }
    throw MapError(MapErrorType::OPEN);
}

void Arcade::PacmanMap::_checkMap()
{
    size_t compt = 0;

    for (size_t i = 0; i < _fileBuffer.size(); i++) {
        if (_fileBuffer[i] == '\n') {
            if ((i - compt * 101) < 100)
                throw MapError(MapErrorType::TOOSHORT, compt);
            if ((i - compt * 101) > 100)
                throw MapError(MapErrorType::TOOLONG, compt);
            compt++;
            continue;
        }
        _checkCharacters(_fileBuffer[i], compt);
    }
}

void Arcade::PacmanMap::_checkCharacters(const char &charact, const size_t &compt)
{
    if (charact == '#' || charact == 'P')
        return;
    if (charact == 'D' || charact == 'G')
        return;
    if (charact == 'B' || charact == 'R')
        return;
    if (charact == 'I' || charact == 'Y')
        return;
    if (charact == ' ' || charact == 'L')
        return; 
    throw MapError(MapErrorType::WRONGCHARACTER, compt);
}

bool Arcade::PacmanMap::_loadMap()
{
    size_t compt = 0;
    std::string temp;

    for (size_t i = 0; i < _fileBuffer.size(); i++) {
        if (_fileBuffer[i] == '\n') {
            temp = _fileBuffer.substr(i - 100, 100);
            _map.push_back(temp);
            temp.clear();
        }
    }
    return false;
}

void Arcade::PacmanMap::_refreshPlayerPos()
{
    for (size_t y = 0; y < _map.size(); y++) {
        for (size_t x = 0; x < _map[y].size(); x++) {
            if (_map[y][x] == 'P') {
                _playerPos.x = x;
                _playerPos.y = y;
                return;
            }
        }
    }
    throw MapError(MapErrorType::PLAYERNOTFOUND);
}

void Arcade::PacmanMap::_refreshEnemiesPos()
{
    std::size_t compt = 0;
    
    for (size_t y = 0; y < _map.size(); y++) {
        for (size_t x = 0; x < _map[y].size(); x++) {
            _checkEnemyCharact(_map[y][x], compt, x, y);
        }
    }
}

void Arcade::PacmanMap::_checkEnemyCharact(
    char &charact,
    size_t &compt,
    const size_t x,
    const size_t y
)
{
    if (charact == 'R') {
        _enemiesPos[0] = { x, y };
        compt++;
    }
    if (charact == 'I') {
        _enemiesPos[1] = { x, y };
        compt++;
    }
    if (charact == 'B') {
        _enemiesPos[2] = { x, y };
        compt++;
    }
    if (charact == 'Y') {
        _enemiesPos[3] = { x, y };
        compt++;
    }
}

bool Arcade::PacmanMap::_manageMapBorder(const PlayerMove &move)
{
    if (move == PlayerMove::LEFT && _playerPos.x == 1) {
        if (_map[_playerPos.y][_playerPos.x - 1] != '#')
            return _computeMove(99 - 4, _playerPos.y, move);
    }
    if (move == PlayerMove::RIGHT && _playerPos.x == 94) {
        if (_map[_playerPos.y][_playerPos.x + 4] != '#')
            return _computeMove(0 + 4, _playerPos.y, move);
    }
    return false;
}

bool Arcade::PacmanMap::_computeMove(const size_t x, const size_t y, const PlayerMove &move)
{
    bool checkColision = _checkPlayerColision(x, y, move);

    _checkWhowIsEaten(x, y, move);
    _map[y][x] = 'P';
    _map[_playerPos.y][_playerPos.x] = ' ';
    _refreshPlayerPos();
    _move = move;
    if (checkColision && !_checkIfWeek())
        _move = PlayerMove::DEATH;
    return checkColision;
}

void Arcade::PacmanMap::_checkWhowIsEaten(const size_t x, const size_t y, const PlayerMove &move)
{
    bool checkColision = false;

    for (size_t w = y; (w - y) < 3; w++) {
        for (size_t z = x; (z - x) < 3; z++) {
            if (_map[w][z] == 'R' && _checkIfWeek()) {
                _setEnemyDeath(0);
                checkColision = true;
            }
            if (_map[w][z] == 'I' && _checkIfWeek()) {
                _setEnemyDeath(1);
                checkColision = true;
            }
            if (_map[w][z] == 'B' && _checkIfWeek()) {
                _setEnemyDeath(2);
                checkColision = true;
            }
            if (_map[w][z] == 'Y' && _checkIfWeek()) {
                _setEnemyDeath(3);
                checkColision = true;
            }
        }
    }
    if (checkColision)
        _refreshEnemiesPos();
    return;
}

bool Arcade::PacmanMap::_checkPlayerColision(const size_t x, const size_t y, const PlayerMove &move)
{
    bool checkColision = false;

    for (size_t w = y; (w - y) < 3; w++) {
        for (size_t z = x; (z - x) < 3; z++) {
            if (_map[w][z] == 'R' && !_checkIfWeek())
                checkColision = true;
            if (_map[w][z] == 'I' && !_checkIfWeek())
                checkColision = true;
            if (_map[w][z] == 'B' && !_checkIfWeek())
                checkColision = true;
            if (_map[w][z] == 'Y' && !_checkIfWeek())
                checkColision = true;
        }
    }
    if (checkColision)
        _refreshEnemiesPos();
    return checkColision;
}

size_t Arcade::PacmanMap::_computeEnemyMove(
    SPos &enemy,
    const SPos (&direction)[4],
    const SPos &target
)
{
    long score = -1;
    long temp = 0;
    size_t pos = 0;

    for (size_t i = 0; i < 4; i++) {
        if (_checkDirection(direction[i])) {
            temp = _computeScore(direction[i], target);
        } else {
            temp = -1;
        }
        if (temp < score && temp != -1) {
            score = temp;
            pos = i;
        }
        if (score == -1) {
            score = temp;
            pos = i;
        }
    }
    return pos;
}

bool Arcade::PacmanMap::_checkDirection(const SPos direction)
{
    size_t x = direction.x;
    size_t y = direction.y;

    if (x < 0 || x > 99 || y < 0 || y > 99)
        return false;
    if (_map[y][x] == ' ') {
        return true;
    }
    return false;
}

long Arcade::PacmanMap::_computeScore(const SPos dirPos, const SPos target)
{
    long temp = 0;

    if (_checkIfWeek()) {
        temp = std::abs(static_cast<long>(dirPos.x + target.x))
        + std::abs(static_cast<long>(dirPos.y + target.y)); 
    } else {
        temp = std::abs(static_cast<long>(dirPos.x - target.x))
        + std::abs(static_cast<long>(dirPos.y - target.y));
    }
    return temp;
}

void Arcade::PacmanMap::_setNewEnemiesPos(
    const SPos &newPos,
    const size_t &dir,
    const SPos &lastPos,
    const size_t &id
)
{
    if (dir == 0 && _enemiesMove[id] != PlayerMove::WEEKNESS)
        _enemiesMove[id] = PlayerMove::LEFT;
    if (dir == 1 && _enemiesMove[id] != PlayerMove::WEEKNESS)
        _enemiesMove[id] = PlayerMove::RIGHT;
    if (dir == 2 && _enemiesMove[id] != PlayerMove::WEEKNESS)
        _enemiesMove[id] = PlayerMove::UP;
    if (dir == 3 && _enemiesMove[id] != PlayerMove::WEEKNESS)
        _enemiesMove[id] = PlayerMove::DOWN;
    _map[newPos.y][newPos.x] = _map[lastPos.y][lastPos.x];
    _map[lastPos.y][lastPos.x] = ' ';
}

void Arcade::PacmanMap::_checkHitbox(
    IPacCompUPtrVect &components,
    IPacCompUPtrVect::iterator &it,
    size_t &score,
    size_t &gumsCount
)
{
    ComponentObjectType type = it->operator->()->getComponentObjectType();
    Pos otherPos = { it->operator->()->getX(), it->operator->()->getY() };
    Pos playerPos = getPlayerPos();

    if (type == ComponentObjectType::BIG_PAC_GUM &&
        _compareSquare(playerPos, otherPos))
    {
        it = components.erase(it);
        score = score + 100;
        if (gumsCount != 0)
            gumsCount--;
        _setWeekness();
        return;
    }
    if (type == ComponentObjectType::LIT_PAC_GUM &&
        _compareSquare(playerPos, otherPos))
    {   
        score = score + 100;
        it = components.erase(it);
        if (gumsCount != 0)
            gumsCount--;
        return;
    }
    it++;
}

bool Arcade::PacmanMap::_compareSquare(const Pos &playerPos, const Pos &otherPos)
{
    bool checkX = false;
    bool checkY = false;

    if (otherPos.x >= playerPos.x && otherPos.x <= playerPos.x + 3)
        checkX = true;
    if (otherPos.y >= playerPos.y && otherPos.y <= playerPos.y + 3)
        checkY = true;
    return checkX && checkY;
}

void Arcade::PacmanMap::_setWeekness()
{
    for (int i = 0; i < 4; i++) {
        if (_enemiesMove[i] != PlayerMove::DEATH)
            _enemiesMove[i] = PlayerMove::WEEKNESS;
    }
    _weaknessClock = std::chrono::high_resolution_clock::now();
}

bool Arcade::PacmanMap::_checkIfWeek()
{
    bool isWeek = false;

    for (int i = 0; i < 4; i++) {
        if (_enemiesMove[i] == PlayerMove::WEEKNESS)
            isWeek = true;
    }
    return isWeek;
}

void Arcade::PacmanMap::_handleWeekness()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
    std::chrono::duration<float> duration;

    newTime = std::chrono::high_resolution_clock::now();
    duration = (newTime - _weaknessClock);
    if (duration.count() >= 10) {
        for (int i = 0; i < 4; i++) {
            if (_enemiesMove[i] == PlayerMove::WEEKNESS)
                _enemiesMove[i] = PlayerMove::RIGHT;
        }
    }
}

void Arcade::PacmanMap::_setEnemyDeath(const std::size_t id)
{
    SPos pos = _enemiesPos[id];

    _enemiesClock[id] = std::chrono::high_resolution_clock::now();
    _enemiesMove[id] = PlayerMove::DEATH;
    if (id == 0) {
        _map[43][41] = 'R';
        _map[pos.y][pos.x] = ' ';
    }
    if (id == 1) {
        _map[49][41] = 'I';
        _map[pos.y][pos.x] = ' ';
    }
    if (id == 2) {
        _map[43][58] = 'B';
        _map[pos.y][pos.x] = ' ';
    }
    if (id == 3) {
        _map[49][58] = 'Y';
        _map[pos.y][pos.x] = ' ';
    }
}

bool Arcade::PacmanMap::_checkEnemyDeath(const std::size_t id)
{
    if (_enemiesMove[id] == PlayerMove::DEATH)
        return true;
    else
        return false;
}

void Arcade::PacmanMap::_handleEnemyDeath()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> newTime;
    std::chrono::duration<float> duration;

    newTime = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 4; i++) {
        duration = (newTime - _enemiesClock[i]);
        if (_checkEnemyDeath(i) && duration.count() >= 10) {
            _enemiesMove[i] = PlayerMove::RIGHT;
        }
    }
}

bool Arcade::PacmanMap::_checkIfInBox(const SPos pos)
{
    return pos.x >= 40 && pos.x <= 65 && pos.y >= 40 && pos.y <= 53;
}