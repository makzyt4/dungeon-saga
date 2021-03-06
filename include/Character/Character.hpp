#ifndef DS_CHARACTER_CHARACTER_HPP
#define DS_CHARACTER_CHARACTER_HPP

#include "../Enum/LookingDirection.hpp"
#include "../Graphics/DrawableObject.hpp"
#include "../Graphics/Animation.hpp"
#include "../Interface/Updatable.hpp"
#include "../Interface/Collidable.hpp"
#include "../Block/Block.hpp"
#include "../Util/RegeneratedValue.hpp"

namespace ds {
    class Character : public DrawableObject, public Updatable,
                      public Collidable {
    protected:
        std::int16_t strength;
        std::int16_t agility;
        std::int16_t intelligence;

        sf::Vector2f velocity;
        sf::Vector2f lastPosition;
        Direction direction;
        bool onGround;
        bool climbing;

        Animation standingRight;
        Animation standingLeft;
        Animation movingRight;
        Animation movingLeft;

        Animation* currentAnimation;

        sf::SoundBuffer* stepBuffer;

        int stepDelay = 0;
    public:
        // TODO void attack();
        // TODO void die();
        void jump();
        void update();
        void draw();
        float getAcceleration();
        float getMaxSpeed();
        void collide(std::vector<Block*>* blocks);
        sf::Vector2f getCenter();
        virtual void init() = 0;
        virtual bool isFlying() const = 0;

        RegeneratedValue health;
        RegeneratedValue stamina;
        RegeneratedValue magicka;
        RegeneratedValue experience;
    };
}

#endif // DS_CHARACTER_CHARACTER_HPP
