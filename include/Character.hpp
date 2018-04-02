#ifndef DS_CHARACTER_HPP
#define DS_CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "DrawableObject.hpp"
#include "LookingDirection.hpp"
#include "ResourceLoader.hpp"
#include "Collidable.hpp"

namespace ds {
    class Character : public DrawableObject, public Collidable {
    protected:
        LookingDirection direction;
        sf::Vector2f position;
        sf::Vector2f velocity;
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
        virtual void init(ResourceLoader* loader) = 0;
        virtual void update(std::vector<Collidable*>* collidables) = 0;
        virtual void setPosition(float x, float y) = 0;

        sf::IntRect getRect();
        ds::Animation* getCurrentAnimation();
    };
}

#endif
