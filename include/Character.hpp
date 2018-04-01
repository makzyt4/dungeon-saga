#ifndef DS_CHARACTER_HPP
#define DS_CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "DrawableObject.hpp"
#include "LookingDirection.hpp"

namespace ds {
    class Character : public DrawableObject {
    protected:
        LookingDirection direction;
        sf::IntRect rect;
        sf::Vector2i position;
        sf::Vector2i health;
        sf::Vector2i baseAttackDmg;
        sf::Vector2i currentAttackDmg;
        int level;
        float speed;

        ds::Animation standingLeft;
        ds::Animation standingRight;
        ds::Animation movingLeft;
        ds::Animation movingRight;
        ds::Animation* currentAnimation;

    public:
        virtual void init() = 0;
        virtual void update(sf::Event* event) = 0;
        virtual void setPosition(int x, int y) = 0;

        sf::IntRect getRect();
        ds::Animation* getCurrentAnimation();
    };
}

#endif
