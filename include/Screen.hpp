#ifndef DS_SCREEN_HPP
#define DS_SCREEN_HPP

#include <functional>
#include <SFML/Graphics.hpp>
#include "Controllable.hpp"
#include "Drawable.hpp"
#include "ResourceLoader.hpp"
#include "Updatable.hpp"
#include "ExitCode.hpp"
#include "MenuObject.hpp"

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

        ExitCode getCode();

        void onClick(MenuObject* object, sf::Event* event, std::function<void()> func);
        void onMouseMove(MenuObject* object, sf::Event* event, std::function<void()> func);

        virtual void init() = 0;
    };
}

#endif  // DS_SCREEN_HPP
