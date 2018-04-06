#include "../../include/Game/Level.hpp"

void ds::Level::setPlayer(PlayerCharacter* player) {
    this->player = player;
}

void ds::Level::addBlock(ds::Block* block, const std::size_t& x,
                         const std::size_t& y) {
    block->setWindow(window);
    block->setLoader(loader);
    block->init();
    printf("%d, %d\n", x * 16, y * 16);
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

void ds::Level::generateLevel(int startX, int startY, std::uint8_t rooms) {
    printf("%d\n", rooms);
    if (rooms == 0) {
        return;
    }
    rooms--;

    int roomIndex = rand() % 10;

    if (roomIndex) {
        for (int w = 0; w < 10; w++) {
            for (int h = 0; h < 6; h++) {
                addBlock(new BlockBackground(), startX + w + 1, startY + h - 2);
            }
        }

        for (int i = 3; i <= 7; i += 2) {
            addBlock(new BlockWindow(), startX + i, startY - 1);
            addBlock(new BlockTorch(), startX + i, startY + 2);
        }
        addBlock(new BlockBrick(), startX + 1, startY);
        addBlock(new BlockBrick(), startX + 9, startY + 1);
        addBlock(new BlockBrick(), startX + 10, startY + 1);

    }

    generateLevel(startX + 10, startY + 4, rooms);
    // Surround with normal blocks
}
