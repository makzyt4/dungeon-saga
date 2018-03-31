#ifndef DS_SCREEN_HPP
#define DS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Controllable.hpp"
#include "Drawable.hpp"
#include "Updatable.hpp"

namespace ds {
    class Screen
        : public Controllable,
          public Drawable,
          public Updatable {

    protected:
        const sf::RenderWindow* window;

    public:
        explicit Screen(const sf::RenderWindow& window);

        void run();
    };
}

#endif  // DS_SCREEN_HPP
