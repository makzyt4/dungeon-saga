#ifndef DS_MENU_OBJECT_HPP
#define DS_MENU_OBJECT_HPP

#include "GameObject.hpp"
#include "MenuState.hpp"

namespace ds {
    class MenuObject : public GameObject {
    protected:
        MenuState state;

    public:
        using GameObject::GameObject;

        MenuState getState() const;

        void setState(MenuState state);
    };
}

#endif // DS_MENU_OBJECT_HPP
