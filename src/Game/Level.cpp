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
            std::vector<Block*>::iterator position = std::find(blocks.begin(),
                                                            blocks.end(), b);
            if (position != blocks.end()) {
                printf("ZNALEZIONO\n");
                blocks.erase(position);
            }
        }
    }

    blocks.push_back(block);
}

void ds::Level::update() {
    for (Block* b : blocks) {
        b->update();
    }
    player->collide(&blocks);
    player->update();
}

void ds::Level::draw() {
    for (Block* block : blocks) {
        block->draw();
    }
    player->draw();
}
