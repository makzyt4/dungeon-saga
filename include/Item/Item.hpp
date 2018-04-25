#ifndef DS_ITEM_ITEM_HPP
#define DS_ITEM_ITEM_HPP

#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"
#include "../Enum/ItemType.hpp"

namespace ds {
    class Item : public DrawableObject {
    protected:
        // Potion
        int healthBonus = 0;
        int magickaBonus = 0;

        // Bomb
        sf::Time timeLeft = sf::seconds(5);
        float radius = 5.0f;

        // Melee
        int meleeDamage = 3;
    
    public:
        ItemType type;
        std::string name = "UnknownItem";

        sf::Sprite sprite;

        virtual void init();
        void draw();
    };
}

#endif // DS_ITEM_ITEM_HPP