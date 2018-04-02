#ifndef DS_TEST_SCREEN_HPP
#define DS_TEST_SCREEN_HPP

#include <vector>
#include "Screen.hpp"
#include "TextButton.hpp"
#include "PlayerCharacter.hpp"
#include "Collidable.hpp"

namespace ds {
    class TestScreen : public Screen {
    private:
        PlayerCharacter hero;
        std::vector<Collidable> collidables;

    public:
        using Screen::Screen;

        void init();
        void update();
        void draw();
        void control();
    };
}

#endif // DS_TEST_SCREEN_HPP
