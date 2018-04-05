#ifndef DS_BLOCK_BLOCK_TORCH_HPP
#define DS_BLOCK_BLOCK_TORCH_HPP

#include "../Graphics/Animation.hpp"
#include "Block.hpp"

namespace ds {
    class BlockTorch : public Block {
    private:
        ds::Animation animation;
    public:
        void init();
        void draw();
        bool isCollidable() const;
        bool isDestructible() const;
        void update() override;
    };
}

#endif // DS_BLOCK_BLOCK_TORCH_HPP
