#ifndef DS_GAME_BLOCK_HPP
#define DS_GAME_BLOCK_HPP

#include "../Graphics/DrawableObject.hpp"

namespace ds {
    class Block : public DrawableObject {
    public:
        virtual void init() = 0;
        virtual bool isCollidable() = 0;
        virtual bool isDestructible() = 0;
    };
}

#endif // DS_GAME_BLOCK_HPP
