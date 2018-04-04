#ifndef DS_CHARACTER_CHARACTER_HPP
#define DS_CHARACTER_CHARACTER_HPP

#include "../Graphics/DrawableObject.hpp"
#include "../Util/RangedValue.hpp"

namespace ds {
    class Character : public DrawableObject {
    protected:
        RangedValue health;
        std::uint8_t strength;
        std::uint8_t agility;
        std::uint8_t intelligence;
        bool onGround;
    public:
        // TODO void attack();
        void jump();
    };
}

#endif // DS_CHARACTER_CHARACTER_HPP
