#ifndef DS_TEST_SCREEN_HPP
#define DS_TEST_SCREEN_HPP

#include "Screen.hpp"
#include "TextButton.hpp"

namespace ds {
    class TestScreen : public Screen {
    public:
        using Screen::Screen;

        void init();
        void update();
        void draw();
        void control();
    };
}

#endif // DS_TEST_SCREEN_HPP
