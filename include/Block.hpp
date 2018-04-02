#ifndef DS_BLOCK_HPP
#define DS_BLOCK_HPP

#include "Collidable.hpp"
#include "DrawableObject.hpp"
#include "GameObject.hpp"

namespace ds {
    class Block : public Collidable, GameObject {
    protected:
        bool destructible;
        bool destroyed;

    public:
        bool isDestructible() const;
        bool isDestroyed() const;

        void setDestructible(const bool& destructible);
        void setDestroyed(const bool& destroyed);
    };
}

#endif // DS_BLOCK_HPP
