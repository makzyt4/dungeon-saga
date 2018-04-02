#ifndef DS_BLOCK_HPP
#define DS_BLOCK_HPP

#include "Collidable.hpp"
#include "DrawableObject.hpp"
#include "GameObject.hpp"

namespace ds {
    class Block : public GameObject {
    protected:
        bool destructible;
        bool destroyed;

    public:
        using GameObject::GameObject;

        bool isDestructible() const;
        bool isDestroyed() const;

        void setDestructible(const bool& destructible);
        void setDestroyed(const bool& destroyed);
        void setPosition(int x, int y);
    };
}

#endif // DS_BLOCK_HPP
