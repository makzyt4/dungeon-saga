#include "../../include/Game/Level.hpp"

ds::Level::Level(const std::uint8_t& difficulty) {
    // TODO More complex when the difficulty is higher
}

void ds::Level::setPlayer(PlayerCharacter* player) {
    this->player = player;
}

void ds::Level::addBlock(ds::Block* block, const std::size_t& x,
                         const std::size_t& y) {
    block->setWindow(window);
    block->setLoader(loader);
    block->init();
    block->setPosition(sf::Vector2f(x * 16, y * 16));

    for (Block* b : blocks) {
        if (block->getRect().intersects(b->getRect())) {
            blocks.erase(std::remove(blocks.begin(), blocks.end(), b),
                         blocks.end());
        }
    }

    blocks.push_back(block);
}

void ds::Level::update() {
    player->update();
    player->collide(&blocks);
}

void ds::Level::draw() {
    for (Block* block : blocks) {
        block->draw();
    }
    player->draw();
}
