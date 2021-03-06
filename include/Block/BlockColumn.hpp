#ifndef DS_BLOCK_BLOCK_COLUMN_HPP
#define DS_BLOCK_BLOCK_COLUMN_HPP

#include "Block.hpp"

namespace ds {
    class BlockColumn : public Block {
        void init();
        void draw();
        bool isCollidable() const;
        bool isDestructible() const;
    };
}

#endif // DS_BLOCK_BLOCK_COLUMN_HPP
