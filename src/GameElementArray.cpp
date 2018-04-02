#include "../include/GameElementArray.hpp"

void ds::GameElementArray::addBlock(Block* block) {
    blocks.push_back(block);
}

void ds::GameElementArray::drawAll(sf::RenderWindow* window) {
    for (Block* block : blocks) {
        block->draw(window);
    }
}
