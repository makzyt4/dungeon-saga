#ifndef DS_BLOCK_BLOCK_WINDOW_HPP
#define DS_BLOCK_BLOCK_WINDOW_HPP

#include "Block.hpp"

namespace ds {
    class BlockWindow : public Block {
        void init();
        void draw();
        bool isCollidable() const;
        bool isDestructible() const;
    };
}

#endif // DS_BLOCK_BLOCK_WINDOW_HPP
