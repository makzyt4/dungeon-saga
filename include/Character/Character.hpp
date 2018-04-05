#ifndef DS_CHARACTER_CHARACTER_HPP
#define DS_CHARACTER_CHARACTER_HPP

#include "../Enum/LookingDirection.hpp"
#include "../Graphics/DrawableObject.hpp"
#include "../Graphics/Animation.hpp"
#include "../Interface/Updatable.hpp"
#include "../Interface/Collidable.hpp"
#include "../Block/Block.hpp"

namespace ds {
    class Character : public DrawableObject, public Updatable,
                      public Collidable {
    protected:
        std::uint8_t health;
        std::uint8_t maxHealth;
        std::uint8_t strength;
        std::uint8_t agility;
        std::uint8_t intelligence;
        sf::Vector2f velocity;
        sf::Vector2f lastPosition;
        LookingDirection direction;
        bool onGround;

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
        void collide(std::vector<Block*>* blocks);
        virtual void init() = 0;
        virtual bool isFlying() const = 0;
    };
}

#endif // DS_CHARACTER_CHARACTER_HPP
