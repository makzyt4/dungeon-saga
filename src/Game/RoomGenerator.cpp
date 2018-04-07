#include "../../include/Game/RoomGenerator.hpp"
#include "../../include/Game/Level.hpp"

ds::RoomGenerator::RoomGenerator() {
    this->level = NULL;
}

ds::RoomGenerator::RoomGenerator(Level* level) {
    this->level = level;
}

void ds::RoomGenerator::generateRooms(const sf::Vector2i& pos,
                                      std::uint8_t rooms,
                                      const bool& startUp) {
    if (rooms == 0) {
        return;
    }
    rooms--;

    if (startUp) {
        int roomIndex = rand() % 4;

        if (roomIndex == 0) {
            generateCorridorWithColumns(pos, rooms);
        } else if (roomIndex == 1) {
            generateCorridor(pos, rooms);
        } else if (roomIndex == 2) {
            generateRoomUpStartTwoExits(pos, rooms);
        } else if (roomIndex == 3) {
            generateCorridorWithWindows(pos, rooms);
        }
    } else {
        int roomIndex = rand() % 5;

        if (roomIndex == 0) {
            generateCorridorWithColumns(pos, rooms);
        } else if (roomIndex == 1) {
            generateCorridor(pos, rooms);
        } else if (roomIndex == 2) {
            generateCorridorWithWindows(pos, rooms);
        } else if (roomIndex == 3) {
            generateRoomDownStartTwoExits(pos, rooms);
        } else if (roomIndex == 4) {
            generateRoomDownStartOneExit(pos, rooms);
        }
    }
}

void ds::RoomGenerator::generateRoomUpStartTwoExits(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    sf::IntRect rect;
    rect.left = pos.x + 16;
    rect.top = pos.y - 32;
    rect.width = 16 * 10;
    rect.height = 16 * 7;

    if (!level->isSpaceAvailable(rect)) {
        return;
    }

    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 7; h++) {
            level->addBlock(new BlockBackground(),
                            pos.x + w + 1,
                            pos.y + h - 2);
        }
    }

    for (int i = 3; i <= 7; i += 2) {
        level->addBlock(new BlockWindow(), pos.x + i, pos.y - 1);
        level->addBlock(new BlockTorch(), pos.x + i, pos.y + 2);
    }

    level->addBlock(new BlockBrick(), pos.x + 1, pos.y + 1);
    level->addBlock(new BlockBrick(), pos.x + 9, pos.y + 1);
    level->addBlock(new BlockBrick(), pos.x + 10, pos.y + 1);
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 4);
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 1);
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 2);
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 3);

    generateRooms(sf::Vector2i(pos.x + 10, pos.y + 4), rooms, true);
    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, false);
}

void ds::RoomGenerator::generateCorridorWithColumns(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    sf::IntRect rect;
    rect.left = pos.x + 32;
    rect.top = pos.y - 32;
    rect.width = 16 * 10;
    rect.height = 16 * 3;

    if (!level->isSpaceAvailable(rect)) {
        return;
    }

    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 3; h++) {
            level->addBlock(new BlockBackground(), pos.x + 1 + w, pos.y - h);
        }
    }

    for (int i = 2; i <= 8; i += 2) {
        level->addBlock(new BlockColumn(), pos.x + i, pos.y - 1);
    }
    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, rand() % 2);
}

void ds::RoomGenerator::generateCorridor(const sf::Vector2i& pos,
                                         const std::uint8_t& rooms) {
    sf::IntRect rect;
    rect.left = pos.x + 32;
    rect.top = pos.y - 32;
    rect.width = 16 * 10;
    rect.height = 16 * 3;

    if (!level->isSpaceAvailable(rect)) {
        return;
    }

    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 3; h++) {
            level->addBlock(new BlockBackground(), pos.x + 1 + w, pos.y - h);
        }
    }

    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, rand() % 2);
}

void ds::RoomGenerator::generateCorridorWithWindows(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    sf::IntRect rect;
    rect.left = pos.x + 32;
    rect.top = pos.y - 32;
    rect.width = 16 * 10;
    rect.height = 16 * 3;

    if (!level->isSpaceAvailable(rect)) {
        return;
    }

    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 3; h++) {
            level->addBlock(new BlockBackground(), pos.x + 1 + w, pos.y - h);
        }
    }

    for (int i = 2; i <= 8; i += 2) {
        level->addBlock(new BlockWindow(), pos.x + i, pos.y - 1);
    }

    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, rand() % 2);
}

void ds::RoomGenerator::generateRoomDownStartTwoExits(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    sf::IntRect rect;
    rect.left = pos.x + 16;
    rect.top = pos.y - 96;
    rect.width = 16 * 10;
    rect.height = 16 * 7;

    if (!level->isSpaceAvailable(rect)) {
        return;
    }

    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 7; h++) {
            level->addBlock(new BlockBackground(),
                            pos.x + w + 1,
                            pos.y - h);
        }
    }

    for (int w = 0; w < 10; w++) {
        level->addBlock(new BlockBrick(),
                        pos.x + w + 1,
                        pos.y - 3);
    }

    for (int h = 0; h < 4; h++) {
        level->addBlock(new BlockLadder(), pos.x + 4, pos.y - h);
        level->addBlock(new BlockLadder(), pos.x + 7, pos.y - h);
    }

    generateRooms(sf::Vector2i(pos.x + 10, pos.y + 4), rooms, true);
    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, false);
}

void ds::RoomGenerator::generateRoomDownStartOneExit(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    sf::IntRect rect;
    rect.left = pos.x + 16;
    rect.top = pos.y - 96;
    rect.width = 16 * 10;
    rect.height = 16 * 7;

    if (!level->isSpaceAvailable(rect)) {
        return;
    }

    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 7; h++) {
            level->addBlock(new BlockBackground(),
                            pos.x + w + 1,
                            pos.y - h);
        }
    }

    for (int w = 3; w <= 7; w++) {
        for (int h = 0; h < 3; h++) {
            Block* block = (w == 3 || w == 7) ?
                           reinterpret_cast<Block*>(new BlockLadder()) :
                           reinterpret_cast<Block*>(new BlockBrick());
            level->addBlock(block, pos.x + w + 1, pos.y - h);
        }
    }

    for (int i = 3; i <= 9; i += 2) {
        level->addBlock(new BlockWindow(), pos.x + i, pos.y - 5);
    }

    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, true);
}
