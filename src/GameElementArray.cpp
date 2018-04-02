#include "../include/GameElementArray.hpp"

void ds::GameElementArray::addBlock(Block* block, int x, int y) {
    block->setPosition(x * 16, y * 16);

    for (Block* block2 : blocks) {
        if (block2->getRect().intersects(block->getRect())) {
            blocks.erase(std::remove(blocks.begin(),
                                     blocks.end(), block2), blocks.end());
        }
    }

    blocks.push_back(block);
}

void ds::GameElementArray::drawAll(sf::RenderWindow* window) {
    for (Block* block : blocks) {
        block->draw(window);
    }
}

std::vector<ds::Block*> ds::GameElementArray::getBlocks() const {
    return blocks;
}
