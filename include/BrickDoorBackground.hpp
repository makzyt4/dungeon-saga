#ifndef DS_BRICK_DOOR_BACKGROUND_HPP
#define DS_BRICK_DOOR_BACKGROUND_HPP

#include "Block.hpp"

namespace ds {
    class BrickDoorBackground : public Block {
    public:
        using Block::Block;

        bool isCollidable();

        void draw(sf::RenderWindow* window);
        void init();
        void setPosition(int x, int y);
    };
}

#endif // DS_BRICK_DOOR_BACKGROUND_HPP
