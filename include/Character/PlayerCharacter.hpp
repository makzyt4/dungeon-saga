#ifndef DS_CHARACTER_PLAYER_CHARACTER_HPP
#define DS_CHARACTER_PLAYER_CHARACTER_HPP

#include "Character.hpp"
#include "../Item/Item.hpp"
#include "../Item/BombItem.hpp"

namespace ds {
    class PlayerCharacter : public Character {
    public:
        Item* items[6];

        void init();
        void setPosition(const sf::Vector2f& position) override;
        void handleKeys();
        bool isCollidable() const;
        bool isFlying() const;
    };
}

#endif // DS_CHARACTER_PLAYER_CHARACTER_HPP
