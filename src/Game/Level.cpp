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

void ds::Level::generateLevel(int startX, int startY, std::uint8_t rooms,
                              bool startUp) {
    if (rooms == 0) {
        return;
    }
    rooms--;

    printf("%d\n", rooms);

    if (startUp) {
        int roomIndex = rand() % 2;

        if (roomIndex == 0) {
            for (int w = 0; w < 10; w++) {
                for (int h = 0; h < 6; h++) {
                    addBlock(new BlockBackground(),
                             startX + w + 1,
                             startY + h - 2);
                }
            }

            for (int i = 3; i <= 7; i += 2) {
                addBlock(new BlockWindow(), startX + i, startY - 1);
                addBlock(new BlockTorch(), startX + i, startY + 2);
            }
            addBlock(new BlockBrick(), startX + 1, startY + 1);
            addBlock(new BlockBrick(), startX + 9, startY + 1);
            addBlock(new BlockBrick(), startX + 10, startY + 1);
            addBlock(new BlockLadder(), startX + 8, startY + 1);
            addBlock(new BlockLadder(), startX + 8, startY + 2);
            addBlock(new BlockLadder(), startX + 8, startY + 3);

            generateLevel(startX + 10, startY + 4, rooms, true);
            generateLevel(startX + 10, startY, rooms, false);
        } else if (roomIndex == 1) {
            for (int w = 0; w < 7; w++) {
                for (int h = 0; h < 3; h++) {
                    addBlock(new BlockBackground(), startX + 1 + w, startY - h);
                }
            }

            for (int i = 2; i <= 6; i += 2) {
                addBlock(new BlockColumn(), startX + i, startY - 1);
            }
            generateLevel(startX + 7, startY, rooms, rand() % 2);
        }
    } else {
        int roomIndex = rand() % 2;

        if (roomIndex == 0) {
            for (int w = 0; w < 9; w++) {
                for (int h = 0; h < 6; h++) {
                    if (h == 3) {
                        addBlock(new BlockBrick(),
                                 startX + w + 1,
                                 startY - h);
                        continue;
                    }
                    addBlock(new BlockBackground(),
                             startX + w + 1,
                             startY - h);
                }
            }

            for (int w = 3; w <= 5; w += 2) {
                for (int h = 0; h < 4; h++) {
                    addBlock(new BlockLadder(),
                             startX + w + 1,
                             startY - h);
                }
            }

            for (int w = 1; w <= 7; w += 2) {
                addBlock(new BlockWindow(),
                         startX + w + 1,
                         startY - 5);
            }
        } else if (roomIndex == 1) {
            for (int w = 0; w < 7; w++) {
                for (int h = 0; h < 3; h++) {
                    addBlock(new BlockBackground(), startX + 1 + w, startY - h);
                }
            }

            for (int i = 2; i <= 6; i += 2) {
                addBlock(new BlockColumn(), startX + i, startY - 1);
            }
            generateLevel(startX + 7, startY, rooms, rand() % 2);
        }
    }

    // Surround with normal blocks
}
