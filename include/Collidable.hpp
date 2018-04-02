#ifndef DS_COLLIDABLE_HPP
#define DS_COLLIDABLE_HPP

namespace ds {
    class Collidable {
    protected:
        sf::IntRect rect;
    public:
        virtual bool isCollidable() = 0;
    };
}

#endif // DS_COLLIDABLE_HPP
