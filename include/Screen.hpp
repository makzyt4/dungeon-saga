#ifndef DS_SCREEN_HPP
#define DS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Controllable.hpp"
#include "Drawable.hpp"
#include "ResourceLoader.hpp"
#include "Updatable.hpp"
#include "ExitCode.hpp"

namespace ds {
    class Screen
        : public Controllable,
          public Drawable,
          public Updatable {

    protected:
        sf::RenderWindow* window;
        ResourceLoader* loader;
        ExitCode code;

    public:
        explicit Screen(sf::RenderWindow* window, ResourceLoader* loader);

        virtual void init() = 0;

        ExitCode getCode();
    };
}

#endif  // DS_SCREEN_HPP
