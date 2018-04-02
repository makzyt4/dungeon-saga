#ifndef DS_BRICK_BLOCK
#define DS_BRICK_BLOCK

#include "Block.hpp"

namespace ds {
    class BrickBlock : public Block {
    public:
        using Block::Block;

        bool isCollidable();

        void draw(sf::RenderWindow* window);
        void init();
    };
}

#endif // DS_BRICK_BLOCK
