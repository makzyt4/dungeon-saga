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
        int roomIndex = rand() % 2;

        if (roomIndex == 0) {
            generateRoomUpStartTwoExits(pos, rooms);
        } else if (roomIndex == 1) {
            generateCorridorWithColumns(pos, rooms);
        }
    } else {
        generateCorridorWithColumns(pos, rooms);
    }
}

void ds::RoomGenerator::generateRoomUpStartTwoExits(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    for (int w = 0; w < 10; w++) {
        for (int h = 0; h < 6; h++) {
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
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 1);
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 2);
    level->addBlock(new BlockLadder(), pos.x + 8, pos.y + 3);

    generateRooms(sf::Vector2i(pos.x + 10, pos.y + 4), rooms, true);
    generateRooms(sf::Vector2i(pos.x + 10, pos.y), rooms, false);
}

void ds::RoomGenerator::generateCorridorWithColumns(const sf::Vector2i& pos,
                                                    const std::uint8_t& rooms) {
    for (int w = 0; w < 7; w++) {
        for (int h = 0; h < 3; h++) {
            level->addBlock(new BlockBackground(), pos.x + 1 + w, pos.y - h);
        }
    }

    for (int i = 2; i <= 6; i += 2) {
        level->addBlock(new BlockColumn(), pos.x + i, pos.y - 1);
    }
    generateRooms(sf::Vector2i(pos.x + 7, pos.y), rooms, rand() % 2);
}
