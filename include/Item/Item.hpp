#ifndef DS_ITEM_ITEM_HPP
#define DS_ITEM_ITEM_HPP

#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"
#include "../Enum/ItemType.hpp"
#include "../Game/Level.hpp"

namespace ds {
    class Item {
    protected:
        ItemType type;
        std::string name = "UnknownItem";

        // Potion
        int healthBonus = 0;
        int magickaBonus = 0;

        // Bomb
        sf::Time timeLeft = sf::seconds(5);
        float radius = 5.0f;

        // Melee
        int meleeDamage = 3;
    
    public:
        sf::Sprite sprite;

        virtual void use(Level* level);
        virtual void init();
    };
}

#endif // DS_ITEM_ITEM_HPP