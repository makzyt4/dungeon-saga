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
    bool isBigRoom = rand() % 5 == 0;

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
            printf("block=%d,%d\n", (offset.x + i) * 16, (offset.y + j) * 16);
        }
    }
}
