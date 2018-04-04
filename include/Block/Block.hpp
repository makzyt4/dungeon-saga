#ifndef DS_BLOCK_BLOCK_HPP
#define DS_BLOCK_BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"

namespace ds {
    class Block : public DrawableObject {
    protected:
        sf::IntRect rect;
    public:
        sf::IntRect getRect() const;

        void setPosition(const sf::Vector2i& position);
        void setRect(const sf::IntRect& rect);

        void init();
        virtual bool isCollidable() = 0;
        virtual bool isDestructible() = 0;
    };
}

#endif // DS_BLOCK_BLOCK_HPP
