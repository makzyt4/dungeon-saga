#ifndef DS_CHARACTER_HPP
#define DS_CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "LookingDirection.hpp"

namespace ds {
    class Character {
    private:
        LookingDirection direction;
        sf::IntRect hitbox;
        int level;
        sf::Vector2i health;
        sf::Vector2i baseAttackDmg;
        sf::Vector2i currentAttackDmg;

        ds::Animation* currentAnimation;

    public:
        virtual void init() = 0;
        virtual void update(sf::Event* event) = 0;
    };
}

#endif
