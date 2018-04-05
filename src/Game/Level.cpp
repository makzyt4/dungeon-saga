#include "../../include/Game/Level.hpp"

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

void ds::Level::generateLevel(const std::uint8_t& rooms) {
    const int offset = 80;
    int startX = offset;
    int startY = offset;

    for (int i = 0; i < rooms; i++) {
        int width = rand() % 4 + 5;
        int height = rand() % 2 + 3;

        const uint8_t direction = rand() % 4;

        if (i == 0) {
            player->setPosition(sf::Vector2f(16 * (startX + width - 1),
                                             16 * (startY + height - 1)));
        }

        for (int w = 0; w < width; w++) {
            for (int h = 0; h < height; h++) {
                addBlock(new BlockBackground(), startX + w, startY + h);
            }
        }

        startX = rand() % 2 == 0 ? startX + width - 2 : startX;
        startY = rand() % 2 == 0 ? startY + height - 2: startY;
    }

    // Surround with normal blocks

}
