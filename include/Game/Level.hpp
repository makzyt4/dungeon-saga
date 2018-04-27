#ifndef DS_GAME_LEVEL_HPP
#define DS_GAME_LEVEL_HPP

#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <vector>
#include "../Character/PlayerCharacter.hpp"
#include "RoomGenerator.hpp"
#include "Bomb.hpp"

namespace ds {
    class Level : public DrawableObject, public Updatable {
    private:
        sf::Vector2f spawnCoords;
        PlayerCharacter* player;
        std::vector<Block*> blocks;
        std::vector<Animation> effects;
        RoomGenerator generator;
        sf::Clock levelClock;

        sf::SoundBuffer* bombBuffer;
    public:
        std::vector<Bomb*> bombs;

        Level();

        void setPlayer(PlayerCharacter* player);

        void addBlock(Block* block, const size_t& x, const size_t& y);
        void explode(const float& x, const float& y, const float& radius);
        void update();
        void draw();
        void init();
        void generateLevel(const std::uint8_t& rooms);
        void surroundBlocks();
        bool isSpaceAvailable(const sf::IntRect& rect);
    };
}

#endif // DS_GAME_LEVEL_HPP
