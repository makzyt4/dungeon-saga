#ifndef DS_PLAYER_CHARACTER_HPP
#define DS_PLAYER_CHARACTER_HPP

#include "Character.hpp"

namespace ds {
    class PlayerCharacter : public Character {
    protected:
        int strength;
        int intelligence;
        int agility;
    public:
        void init();
        void update(sf::Event* event);
        void draw(sf::RenderWindow* window);
    };
}

#endif // DS_PLAYER_CHARACTER_HPP
