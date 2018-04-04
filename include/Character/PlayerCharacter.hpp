#ifndef DS_CHARACTER_PLAYER_CHARACTER_HPP
#define DS_CHARACTER_PLAYER_CHARACTER_HPP

#include "Character.hpp"

namespace ds {
    class PlayerCharacter : public Character {
    public:
        void init();
        void setPosition(const sf::Vector2f& position) override;
        void handleKeys(sf::Event* event);
        bool isCollidable() const;
    };
}

#endif // DS_CHARACTER_PLAYER_CHARACTER_HPP
