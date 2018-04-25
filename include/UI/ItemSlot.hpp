#ifndef DS_UI_ITEMSLOT_HPP
#define DS_UI_ITEMSLOT_HPP

#include "../Item/Item.hpp"
#include "Node.hpp"

namespace ds {
    class ItemSlot : public Node {
    public:
        Item* item = NULL;
        bool selected = false;

        void draw();
        void init();
        void onMouseHoverAction(sf::Event* event);
        void onMousePressedAction(sf::Event* event);
        void onMouseReleasedAction(sf::Event* event);
    };
}

#endif // DS_UI_ITEMSLOT_HPP