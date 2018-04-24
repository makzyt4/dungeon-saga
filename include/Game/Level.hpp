#ifndef DS_GAME_LEVEL_HPP
#define DS_GAME_LEVEL_HPP

#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <vector>
#include "../Character/PlayerCharacter.hpp"
#include "RoomGenerator.hpp"

namespace ds {
    class Level : public DrawableObject, public Updatable {
    private:
        sf::Vector2f spawnCoords;
        PlayerCharacter* player;
        std::vector<Block*> blocks;
        RoomGenerator generator;

        sf::Clock playerClock;
    public:
        Level();

        void setPlayer(PlayerCharacter* player);

        void addBlock(Block* block, const size_t& x, const size_t& y);
        void update();
        void draw();
        void generateLevel(const std::uint8_t& rooms);
        void surroundBlocks();
        bool isSpaceAvailable(const sf::IntRect& rect);
    };
}

#endif // DS_GAME_LEVEL_HPP
