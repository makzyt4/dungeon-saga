#ifndef DS_CHARACTER_PLAYER_CHARACTER_HPP
#define DS_CHARACTER_PLAYER_CHARACTER_HPP

#include "Character.hpp"

namespace ds {
    class PlayerCharacter : public Character {
    public:
        int bombs;
        int hPotions;
        int mPotions;

        void init();
        void setPosition(const sf::Vector2f& position) override;
        void handleKeys();
        bool isCollidable() const;
        bool isFlying() const;
    };
}

#endif // DS_CHARACTER_PLAYER_CHARACTER_HPP
