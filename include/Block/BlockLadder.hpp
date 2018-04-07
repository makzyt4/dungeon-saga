#ifndef DS_BLOCK_BLOCK_LADDER_HPP
#define DS_BLOCK_BLOCK_LADDER_HPP

#include "Block.hpp"

namespace ds {
    class BlockLadder : public Block {
        bool isClimbable() const;
        bool isDestructible() const;
        bool isCollidable() const;
        void draw();
    };
}

#endif // DS_BLOCK_BLOCK_LADDER_HPP
