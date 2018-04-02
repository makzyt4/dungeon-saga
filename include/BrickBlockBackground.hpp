#ifndef DS_BRICK_BLOCK_BACKGROUND_HPP
#define DS_BRICK_BLOCK_BACKGROUND_HPP

#include "Block.hpp"

namespace ds {
    class BrickBlockBackground : public Block {
    public:
        using Block::Block;

        bool isCollidable();

        void draw(sf::RenderWindow* window);
        void init();
    };
}

#endif // DS_BRICK_BLOCK_BACKGROUND_HPP
