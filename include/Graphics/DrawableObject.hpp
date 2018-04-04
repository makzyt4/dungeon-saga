#ifndef DS_INTERFACE_DRAWABLEOBJECT_HPP
#define DS_INTERFACE_DRAWABLEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../Interface/Drawable.hpp"
#include "../Loader/ResourceLoader.hpp"

namespace ds {
    class DrawableObject : public Drawable {
    protected:
        sf::Vector2f position;
        sf::IntRect rect;
        sf::RenderWindow* window;
        ResourceLoader* loader;
    public:
        sf::Vector2f getPosition() const;
        sf::IntRect getRect() const;

        virtual void setPosition(const sf::Vector2f& position);
        void setRect(const sf::IntRect& rect);

        void setWindow(sf::RenderWindow* window);
        void setLoader(ResourceLoader* loader);
    };
}

#endif // DS_INTERFACE_DRAWABLEOBJECT_HPP
