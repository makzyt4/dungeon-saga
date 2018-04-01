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
#include "RelativeLayout.hpp"

namespace ds {
    class Screen
        : public Controllable,
          public Drawable,
          public Updatable {

    protected:
        RelativeLayout* layout;
        sf::RenderWindow* window;
        ResourceLoader* loader;
        ExitCode code;

    public:
        explicit Screen(sf::RenderWindow* window, ResourceLoader* loader);

        ExitCode getCode();

        virtual void init() = 0;
        void generateView();
    };
}

#endif  // DS_SCREEN_HPP
