#ifndef DS_MAIN_SCREEN_HPP
#define DS_MAIN_SCREEN_HPP

#include "Screen.hpp"
#include "TextButton.hpp"

namespace ds {
    class MainScreen : public Screen {
        ds::TextButton startButton;
        ds::TextButton optionsButton;
        ds::TextButton quitButton;

    public:
        using Screen::Screen;

        void init();
        void update();
        void draw();
        void control();
    };
}

#endif // DS_MAIN_SCREEN_HPP
