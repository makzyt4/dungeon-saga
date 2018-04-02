#ifndef DS_GAME_OBJECT_HPP
#define DS_GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "DrawableObject.hpp"
#include "ResourceLoader.hpp"
#include "Updatable.hpp"

namespace ds {
    class GameObject : public DrawableObject, public Collidable {
    protected:
        ds::ResourceLoader* loader;
        sf::Texture* texture;
        sf::IntRect rect;

    public:
        GameObject();
        GameObject(ResourceLoader* loader);

        sf::IntRect getRect() const;

        void setLoader(ResourceLoader* loader);

        virtual void init() = 0;
        virtual void setPosition(int x, int y) = 0;
    };
}

#endif // DS_GAME_OBJECT_HPP
