#ifndef DS_TEST_SCREEN_HPP
#define DS_TEST_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "Animation.hpp"
#include "ResourceLoader.hpp"

namespace ds {
    class TestScreen : public Screen {
    private:
        sf::CircleShape shape;
        ds::Animation animation;
    public:
        using Screen::Screen;

        void init();
        void update();
        void draw();
        void control();
    };
}

#endif // DS_TEST_SCREEN_HPP
