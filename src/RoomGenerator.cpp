#include "../include/RoomGenerator.hpp"

void ds::RoomGenerator::setOffset(sf::Vector2i offset) {
    this->offset = offset;
}

void ds::RoomGenerator::setLoader(ds::ResourceLoader* loader) {
    this->loader = loader;
}

void ds::RoomGenerator::setLevelSize(const int& width, const int& height) {
    levelSize = sf::Vector2i(width, height);
}

void ds::RoomGenerator::setElements(GameElementArray* elements) {
    this->elements = elements;
}

void ds::RoomGenerator::generateRoom() {
    bool isBigRoom = rand() % 50 == 0;

    const int width = isBigRoom ? rand() % 21 + 10 : rand() % 6 + 5;
    const int height = isBigRoom ? rand() % 11 + 5 : rand() % 3 + 3;

    const int x = rand() % levelSize.x;
    const int y = rand() % levelSize.y;

    const int floor = y + height;

    for (int i = x; i < width + x; i++) {
        for (int j = y; j < height + y; j++) {
            Block* block = new BrickBlockBackground();
            block->setLoader(loader);
            block->init();
            elements->addBlock(block, offset.x + i, offset.y + j);
        }
    }

    rooms.push_back(sf::IntRect(x, y, width, height));
}

void ds::RoomGenerator::generateRooms(std::uint8_t number) {
    for (std::uint8_t i = 0; i < number; i++) {
        generateRoom();
    }

    addCorridors();
    surroundNotCollidableBlocks();
}

void ds::RoomGenerator::surroundNotCollidableBlocks() {
    // Now surround background blocks with normal, static blocks
    for (Block* block : elements->getBlocks()) {
        bool emptyTop = true;
        bool emptyBottom = true;
        bool emptyLeft = true;
        bool emptyRight = true;
        bool emptyTopLeft = true;
        bool emptyTopRight = true;
        bool emptyBottomLeft = true;
        bool emptyBottomRight = true;

        // Top
        sf::IntRect topRect = block->getRect();
        topRect.top -= 16;

        // Bottom
        sf::IntRect bottomRect = block->getRect();
        bottomRect.top += 16;

        // Left
        sf::IntRect leftRect = block->getRect();
        leftRect.left -= 16;

        // Left
        sf::IntRect rightRect = block->getRect();
        rightRect.left += 16;

        // Top-left
        sf::IntRect topLeftRect = block->getRect();
        topLeftRect.left -= 16;
        topLeftRect.top -= 16;

        // Top-right
        sf::IntRect topRightRect = block->getRect();
        topRightRect.left += 16;
        topRightRect.top -= 16;

        // Bottom-left
        sf::IntRect bottomLeftRect = block->getRect();
        bottomLeftRect.left -= 16;
        bottomLeftRect.top += 16;

        // Bottom-right
        sf::IntRect bottomRightRect = block->getRect();
        bottomRightRect.left += 16;
        bottomRightRect.top += 16;

        for (Block* block2 : elements->getBlocks()) {
            if (block2->isCollidable() || block == block2) {
                continue;
            }

            // Top
            if (topRect.intersects(block2->getRect())) {
                emptyTop = false;
            }

            // Bottom
            if (bottomRect.intersects(block2->getRect())) {
                emptyBottom = false;
            }

            // Left
            if (leftRect.intersects(block2->getRect())) {
                emptyLeft = false;
            }

            // Right
            if (rightRect.intersects(block2->getRect())) {
                emptyRight = false;
            }

            // Top-left
            if (topLeftRect.intersects(block2->getRect())) {
                emptyTopLeft = false;
            }

            // Top-right
            if (topRightRect.intersects(block2->getRect())) {
                emptyTopRight = false;
            }

            // Bottom-left
            if (bottomLeftRect.intersects(block2->getRect())) {
                emptyBottomLeft = false;
            }

            // Bottom-right
            if (bottomRightRect.intersects(block2->getRect())) {
                emptyBottomRight = false;
            }
        }

        int x = block->getRect().left / 16;
        int y = block->getRect().top / 16;


        if (emptyTop) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x, y - 1);
        }
        if (emptyBottom) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x, y + 1);
        }
        if (emptyLeft) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x - 1, y);
        }
        if (emptyRight) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x + 1, y);
        }
        if (emptyTopLeft) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x - 1, y - 1);
        }
        if (emptyTopRight) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x + 1, y - 1);
        }
        if (emptyBottomLeft) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x - 1, y + 1);
        }
        if (emptyBottomRight) {
            Block* brick = new BrickBlock();
            brick->setLoader(loader);
            brick->init();

            elements->addBlock(brick, x + 1, y + 1);
        }
    }
}

void ds::RoomGenerator::addPlayer(ds::PlayerCharacter* player) {
    bool foundPlaceForPlayer = false;
    int index = 0;

    while (!foundPlaceForPlayer) {
        index = rand() % elements->getBlocks().size();
        Block* block = elements->getBlocks()[index];

        if (block->isCollidable()) {
            continue;
        }

        sf::IntRect rect = block->getRect();
        rect.top += 16;

        for (Block* block2 : elements->getBlocks()) {
            if (block2->isCollidable() || !rect.intersects(block2->getRect())) {
                continue;
            }

            foundPlaceForPlayer = true;
            break;
        }
    }

    sf::IntRect foundPosition = elements->getBlocks()[index]->getRect();
    player->setPosition(foundPosition.left, foundPosition.top);
}

void ds::RoomGenerator::addCorridors() {
    for (sf::IntRect room : rooms) {
        for (sf::IntRect room2 : rooms) {
            if (room == room2
                || room2.top < room.top
                || room2.left < room.left) {
                continue;
            }

            sf::IntRect room3 = room2;
            room3.top = room.top;

            if (room3.intersects(room)) {
                int xMin = std::min(room.left, room3.left);
                int xMax = xMin + std::max(room.width, room3.width);

                int corridorX = (rand() % (xMax - xMin)) + xMin;

                for (int i = room.top + room.height; i < room2.top; i++) {
                    Block* block = new BrickBlockBackground();
                    block->setLoader(loader);
                    block->init();
                    elements->addBlock(block, offset.x + corridorX,
                                       offset.y + i);
                    elements->addBlock(block, offset.x + corridorX + 1,
                                       offset.y + i);
                }
            }

            room3 = room2;
            room3.left = room.left;

            if (room3.intersects(room)) {
                int yMin = std::min(room.top, room3.top);
                int yMax = yMin + std::max(room.height, room3.height);

                int corridorY = (rand() % (yMax - yMin)) + yMin;

                for (int i = room.left + room.width; i < room2.left; i++) {
                    Block* block = new BrickBlockBackground();
                    block->setLoader(loader);
                    block->init();
                    elements->addBlock(block, offset.x + i,
                                       offset.y + corridorY);
                }
            }
        }
    }
}
