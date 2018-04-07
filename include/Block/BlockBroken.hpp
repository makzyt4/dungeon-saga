#ifndef DS_BLOCK_BLOCK_BROKEN_HPP
#define DS_BLOCK_BLOCK_BROKEN_HPP

#include "Block.hpp"

namespace ds {
    class BlockBroken : public Block {
    public:
        bool isDestructible() const;
        bool isCollidable() const;
        void draw();
    };
}

#endif // DS_BLOCK_BLOCK_BROKEN_HPP
