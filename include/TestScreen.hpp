#ifndef DS_TEST_SCREEN_HPP
#define DS_TEST_SCREEN_HPP

#include <vector>
#include "Screen.hpp"
#include "TextButton.hpp"
#include "PlayerCharacter.hpp"
#include "GameElementArray.hpp"
#include "BrickBlock.hpp"
#include "Text.hpp"

namespace ds {
    class TestScreen : public Screen {
    private:
        PlayerCharacter hero;
        GameElementArray elements;
        Text text;

    public:
        using Screen::Screen;

        void init();
        void update();
        void draw();
        void control();
    };
}

#endif // DS_TEST_SCREEN_HPP
