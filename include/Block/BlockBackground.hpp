#ifndef DS_BLOCK_BLOCK_BACKGROUND_HPP
#define DS_BLOCK_BLOCK_BACKGROUND_HPP

#include "Block.hpp"

namespace ds {
    class BlockBackground : public Block {
        void draw();
        bool isCollidable() const;
        bool isDestructible() const;
    };
}

#endif // DS_BLOCK_BLOCK_BACKGROUND_HPP
