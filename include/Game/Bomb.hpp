#ifndef DS_GAME_BOMB_HPP
#define DS_GAME_BOMB_HPP

#include "../Graphics/DrawableObject.hpp"
#include "../Interface/Updatable.hpp"

namespace ds {
    class Bomb : public DrawableObject, public Updatable {
    private:
        bool exploded;
        sf::Clock bombClock;
    public:
        void init();
        void draw();
        void update();
    };
}

#endif // DS_GAME_BOMB_HPP