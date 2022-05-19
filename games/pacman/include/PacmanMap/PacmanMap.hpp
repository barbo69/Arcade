/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-baptiste.barbotin
** File description:
** PacmanMap
*/

#ifndef PACMANMAP_HPP_
#define PACMANMAP_HPP_

#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <filesystem>
#include <chrono>
#include "IPacmanComponent.hpp"


namespace Arcade {

    using IPacCompUPtr = std::unique_ptr<IPacmanComponent>;
    using IPacCompUPtrVect = std::vector<std::unique_ptr<IPacmanComponent>>;

    class PacmanMap {
        public:
            struct Pos {
                int x;
                int y;
            };

            struct SPos {
                size_t x;
                size_t y;
            };

            enum class PlayerMove {
                LEFT,
                RIGHT,
                UP,
                DOWN,
                DEATH,
                WEEKNESS
            };

            PacmanMap();
            ~PacmanMap();
            Pos getPlayerPos() const;
            Pos getEnemyPos(const size_t &id) const;
            bool movePlayer(const PlayerMove &move);
            void moveEnemies();
            PlayerMove getPlayerMove() const;
            PlayerMove getEnemyMove(const size_t &id) const;
            void computeBigPacGums(
                IPacCompUPtrVect &components,
                size_t &compCompt,
                size_t &gumsCount
            );
            void computeLittlePacGums(
                IPacCompUPtrVect &components,
                size_t &compCompt,
                size_t &gumsCount
            );
            void checkGumsHitbox(
                IPacCompUPtrVect &components,
                size_t &score,
                size_t &gumsCount
            );

        private:
            std::string _fileBuffer;
            std::vector<std::string> _map;
            SPos _playerPos;
            SPos _enemiesPos[4];
            PlayerMove _move;
            PlayerMove _enemiesMove[4];
            std::chrono::time_point<std::chrono::high_resolution_clock> _enemiesClock[4];
            std::chrono::time_point<std::chrono::high_resolution_clock> _weaknessClock;
            void _openFile(const std::filesystem::path &filePath);
            void _checkMap();
            void _checkCharacters(const char &charact, const size_t &compt);
            bool _loadMap();
            void _refreshPlayerPos();
            void _refreshEnemiesPos();
            void _checkEnemyCharact(
                char &charact,
                size_t &compt,
                const size_t x,
                const size_t y
            );
            bool _manageMapBorder(const PlayerMove &move);
            bool _computeMove(const size_t x, const size_t y, const PlayerMove &move);
            bool _checkPlayerColision(const size_t x, const size_t y, const PlayerMove &move);
            void _checkWhowIsEaten(const size_t x, const size_t y, const PlayerMove &move);
            size_t _computeEnemyMove(
                SPos &enemy,
                const SPos (&direction)[4],
                const SPos &target
            );
            bool _checkDirection(const SPos dirPos);
            long _computeScore(const SPos dirPos, const SPos target);
            void _setNewEnemiesPos(
                const SPos &newPos,
                const size_t &dir,
                const SPos &lastPos,
                const size_t &id
            );
            void _checkHitbox(
                IPacCompUPtrVect &components,
                IPacCompUPtrVect::iterator &it,
                size_t &score,
                size_t &gumsCount
            );
            bool _compareSquare(const Pos &playerPos, const Pos &otherPos);
            void _setWeekness();
            bool _checkIfWeek();
            void _handleWeekness();
            void _setEnemyDeath(const std::size_t id);
            bool _checkEnemyDeath(const std::size_t id);
            void _handleEnemyDeath();
            bool _checkIfInBox(const SPos pos);
    };
}

#endif /* !PACMANMAP_HPP_ */
