#ifndef DS_PLAYER_CHARACTER_HPP
#define DS_PLAYER_CHARACTER_HPP

#include <cmath>
#include "Character.hpp"

namespace ds {
    class PlayerCharacter : public Character {
    protected:
        int strength;
        int intelligence;
        int agility;
    public:
        void init(ResourceLoader* loader);
        void update(std::vector<Collidable*>* collidables);
        void draw(sf::RenderWindow* window);
        void setPosition(float x, float y);
        void handleKeys();
        bool isCollidable();
    };
}

#endif // DS_PLAYER_CHARACTER_HPP
