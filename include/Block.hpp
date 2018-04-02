#ifndef DS_BLOCK_HPP
#define DS_BLOCK_HPP

#include "Collidable.hpp"
#include "DrawableObject.hpp"
#include "GameObject.hpp"

namespace ds {
    class Block : public Collidable, DrawableObject, GameObject {
    protected:
        bool destructible;

    public:
        bool isDestructible() const;

        void setDestructible(const bool& destructible);
    };
}

#endif // DS_BLOCK_HPP
