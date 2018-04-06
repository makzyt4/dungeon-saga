#ifndef DS_GAME_LEVEL_HPP
#define DS_GAME_LEVEL_HPP

#include <algorithm>
#include <vector>
#include "../Character/PlayerCharacter.hpp"
#include "../Block/BlockBrick.hpp"
#include "../Block/BlockBackground.hpp"

namespace ds {
    class Level : public DrawableObject, public Updatable {
    private:
        sf::Vector2f spawnCoords;
        PlayerCharacter* player;
        std::vector<Block*> blocks;
    public:
        void setPlayer(PlayerCharacter* player);
        void addBlock(Block* block, const size_t& x, const size_t& y);
        void update();
        void draw();
        void generateLevel(int startX, int startY, const std::uint8_t& rooms);
    };
}

#endif // DS_GAME_LEVEL_HPP
