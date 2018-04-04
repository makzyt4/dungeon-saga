#ifndef DS_CHARACTER_CHARACTER_HPP
#define DS_CHARACTER_CHARACTER_HPP

#include "../Enum/LookingDirection.hpp"
#include "../Graphics/DrawableObject.hpp"
#include "../Graphics/Animation.hpp"
#include "../Interface/Updatable.hpp"

namespace ds {
    class Character : public DrawableObject, public Updatable {
    protected:
        std::uint8_t health;
        std::uint8_t maxHealth;
        std::uint8_t strength;
        std::uint8_t agility;
        std::uint8_t intelligence;
        sf::Vector2f velocity;
        bool onGround;
        LookingDirection direction;

        Animation standingRight;
        Animation standingLeft;
        Animation movingRight;
        Animation movingLeft;

        Animation* currentAnimation;
    public:
        // TODO void attack();
        // TODO void die();
        void jump();
        void update();
        void draw();
        float getSpeed();
        virtual void init() = 0;
    };
}

#endif // DS_CHARACTER_CHARACTER_HPP
