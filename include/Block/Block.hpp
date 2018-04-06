#ifndef DS_BLOCK_BLOCK_HPP
#define DS_BLOCK_BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"
#include "../Interface/Collidable.hpp"
#include "../Interface/Updatable.hpp"

namespace ds {
    class Block : public DrawableObject, public Collidable, public Updatable {
    public:
        virtual void init();
        virtual void update();
        virtual bool isClimbable();
        virtual bool isDestructible() const = 0;
    };
}

#endif // DS_BLOCK_BLOCK_HPP
