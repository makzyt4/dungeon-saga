#ifndef DS_ROOM_ROOM_HPP
#define DS_ROOM_ROOM_HPP

#include <SFML/Graphics.hpp>
#include "../Block/Block.hpp"

namespace ds {
    class Room {
    private:
        sf::Vector2i position;
    public:
        void setPosition(const sf::Vector2i& position);
        virtual std::vector<std::vector<Block*>> generateBlocks();
    };
}

#endif // DS_ROOM_ROOM_HPP
