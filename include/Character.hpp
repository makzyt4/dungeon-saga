#ifndef DS_CHARACTER_HPP
#define DS_CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "LookingDirection.hpp"

namespace ds {
    class Character {
    private:
        LookingDirection direction;
        sf::IntRect hitbox;
        int health;
        int healthMax;

        ds::Animation* currentAnimation;

    public:
        virtual void init() = 0;
        virtual void update(sf::Event* event) = 0;
    };
}

#endif
