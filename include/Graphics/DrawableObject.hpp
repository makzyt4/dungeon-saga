#ifndef DS_INTERFACE_DRAWABLEOBJECT_HPP
#define DS_INTERFACE_DRAWABLEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../Interface/Drawable.hpp"

namespace ds {
    class DrawableObject : public Drawable {
    protected:
        sf::RenderWindow* window;
    public:
        void setWindow(sf::RenderWindow* window);
    };
}

#endif // DS_INTERFACE_DRAWABLEOBJECT_HPP
