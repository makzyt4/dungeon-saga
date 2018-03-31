#ifndef DS_DRAWABLE_OBJECT_HPP
#define DS_DRAWABLE_OBJECT_HPP

#include <SFML/Graphics.hpp>

namespace ds {
    class DrawableObject {
    public:
        virtual void draw(sf::RenderWindow* window) = 0;
    };
}

#endif // DS_DRAWABLE_OBJECT_HPP
