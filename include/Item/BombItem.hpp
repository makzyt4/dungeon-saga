#ifndef DS_ITEM_BOMBITEM_HPP
#define DS_ITEM_BOMBITEM_HPP

#include "Item.hpp"

namespace ds {
    class BombItem : public Item {
    public:
        void use(Level* level);
        void init();
    };
}

#endif // DS_ITEM_BOMBITEM_HPP