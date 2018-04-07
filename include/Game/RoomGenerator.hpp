#ifndef DS_GAME_ROOM_GENERATOR_HPP
#define DS_GAME_ROOM_GENERATOR_HPP

#include "../Block/BlockBrick.hpp"
#include "../Block/BlockBackground.hpp"
#include "../Block/BlockTorch.hpp"
#include "../Block/BlockWindow.hpp"
#include "../Block/BlockLadder.hpp"
#include "../Block/BlockColumn.hpp"
#include "../Block/BlockBroken.hpp"

namespace ds {
    class Level;

    class RoomGenerator {
    private:
        Level* level;
    public:
        RoomGenerator();
        RoomGenerator(Level* level);

        void generateRooms(const sf::Vector2i& startPos,
                           std::uint8_t rooms,
                           const bool& startUp);

        void generateRoomUpStartTwoExits(const sf::Vector2i& position,
                                         const std::uint8_t& rooms);
        void generateRoomUpStartOneExit(const sf::Vector2i& position,
                                         const std::uint8_t& rooms);
        void generateRoomDownStartTwoExits(const sf::Vector2i& position,
                                           const std::uint8_t& rooms);
        void generateRoomDownStartOneExit(const sf::Vector2i& position,
                                          const std::uint8_t& rooms);
        void generateCorridorWithColumns(const sf::Vector2i& position,
                                         const std::uint8_t& rooms);
        void generateCorridor(const sf::Vector2i& position,
                              const std::uint8_t& rooms);
        void generateCorridorWithWindows(const sf::Vector2i& position,
                                         const std::uint8_t& rooms);
    };
}

#endif // DS_GAME_ROOM_GENERATOR_HPP
