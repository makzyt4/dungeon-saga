#ifndef DS_BLOCK_BLOCK_HPP
#define DS_BLOCK_BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"

namespace ds {
    class Block : public DrawableObject, public Collidable {
    public:
        void init();
        virtual bool isDestructible() = 0;
    };
}

#endif // DS_BLOCK_BLOCK_HPP
