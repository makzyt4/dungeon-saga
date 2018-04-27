#ifndef DS_GAME_BOMB_HPP
#define DS_GAME_BOMB_HPP

#include "../Graphics/DrawableObject.hpp"
#include "../Interface/Updatable.hpp"
#include "../Graphics/Text.hpp"
#include "../Graphics/Animation.hpp"

namespace ds {
    class Bomb : public DrawableObject, public Updatable {
    private:
        Animation explosion;
    public:
        bool exploded;
        bool explosionEnded;
        sf::Clock bombClock;

        void init();
        void draw();
        void update();
    };
}

#endif // DS_GAME_BOMB_HPP