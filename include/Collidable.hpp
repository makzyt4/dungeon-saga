#ifndef DS_COLLIDABLE_HPP
#define DS_COLLIDABLE_HPP

#include <SFML/Graphics.hpp>

namespace ds {
    class Collidable {
    public:
        virtual bool isCollidable() = 0;
    };
}

#endif // DS_COLLIDABLE_HPP
