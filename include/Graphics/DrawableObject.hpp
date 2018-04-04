#ifndef DS_INTERFACE_DRAWABLEOBJECT_HPP
#define DS_INTERFACE_DRAWABLEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../Interface/Drawable.hpp"
#include "../Loader/ResourceLoader.hpp"

namespace ds {
    class DrawableObject : public Drawable {
    protected:
        sf::Vector2i position;
        sf::RenderWindow* window;
        ResourceLoader* loader;
    public:
        void setWindow(sf::RenderWindow* window);
        void setLoader(ResourceLoader* loader);
    };
}

#endif // DS_INTERFACE_DRAWABLEOBJECT_HPP
