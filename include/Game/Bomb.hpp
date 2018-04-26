#ifndef DS_GAME_BOMB_HPP
#define DS_GAME_BOMB_HPP

#include "../Graphics/DrawableObject.hpp"
#include "../Interface/Updatable.hpp"
#include "../Graphics/Text.hpp"

namespace ds {
    class Bomb : public DrawableObject, public Updatable {
    public:
        bool exploded;
        sf::Clock bombClock;

        void init();
        void draw();
        void update();
    };
}

#endif // DS_GAME_BOMB_HPP