#ifndef DS_SCREEN_HPP
#define DS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Controllable.hpp"
#include "Drawable.hpp"
#include "ResourceLoader.hpp"
#include "Updatable.hpp"

namespace ds {
    class Screen
        : public Controllable,
          public Drawable,
          public Updatable {

    protected:
        sf::RenderWindow* window;
        ResourceLoader* loader;

    public:
        explicit Screen(sf::RenderWindow* window, ResourceLoader* loader);

        virtual void init() = 0;
    };
}

#endif  // DS_SCREEN_HPP
