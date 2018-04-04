#include "../../include/Game/Level.hpp"

ds::Level::Level(const std::size_t& width, const std::size_t& height) {
    for (int i = 0; i < height; i++) {
        std::vector<Block*> row;
        for (int j = 0; j < width; j++) {
            row.push_back(NULL);
        }
        blocks.push_back(row);
    }
}

void ds::Level::setPlayer(PlayerCharacter* player) {
    this->player = player;
}

void ds::Level::addBlock(ds::Block* block, const std::size_t& x,
                         const std::size_t& y) {
    blocks[y][x] = block;
}
