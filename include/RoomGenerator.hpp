#ifndef DS_ROOM_GENERATOR_HPP
#define DS_ROOM_GENERATOR_HPP

#include "GameElementArray.hpp"
#include "BrickBlock.hpp"
#include "BrickBlockBackground.hpp"
#include "BrickDoorBackground.hpp"
#include "ResourceLoader.hpp"

namespace ds {
    class RoomGenerator {
    private:
        ResourceLoader* loader;
        GameElementArray* elements;
        sf::Vector2i levelSize;
        sf::Vector2i offset;

    public:
        void setOffset(sf::Vector2i offset);
        void setLoader(ResourceLoader* loader);
        void setLevelSize(const int& width, const int& height);
        void setElements(GameElementArray* elements);
        void generateRoom();
        void generateRooms(std::uint8_t number);
    };
}

#endif // DS_ROOM_GENERATOR_HPP
