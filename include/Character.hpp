#ifndef DS_CHARACTER_HPP
#define DS_CHARACTER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "DrawableObject.hpp"
#include "LookingDirection.hpp"
#include "ResourceLoader.hpp"
#include "GameElementArray.hpp"

namespace ds {
    class Character : public DrawableObject, public Collidable {
    protected:
        sf::IntRect rect;

        LookingDirection direction;
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2i health;
        sf::Vector2i baseAttackDmg;
        sf::Vector2i currentAttackDmg;
        int level;
        float speed;
        float jumpHeight;
        bool onGround;

        ds::Animation standingLeft;
        ds::Animation standingRight;
        ds::Animation movingLeft;
        ds::Animation movingRight;
        ds::Animation* currentAnimation;

        sf::Sound stepSound;
        std::uint8_t stepDelay;

    public:
        virtual void init(ResourceLoader* loader) = 0;
        virtual void update(GameElementArray* elements) = 0;
        virtual void setPosition(float x, float y) = 0;

        void jump();

        sf::IntRect getRect();
        ds::Animation* getCurrentAnimation();
        sf::Vector2i getCenter();
    };
}

#endif
