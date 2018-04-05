#ifndef DS_BLOCK_BLOCK_BRICK_HPP
#define DS_BLOCK_BLOCK_BRICK_HPP

#include "Block.hpp"

namespace ds {
    class BlockBrick : public Block {
        void draw();
        bool isCollidable() const;
        bool isDestructible() const;
    };
}

#endif // DS_BLOCK_BLOCK_BRICK_HPP
