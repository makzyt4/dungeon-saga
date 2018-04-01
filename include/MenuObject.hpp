#ifndef DS_MENU_OBJECT_HPP
#define DS_MENU_OBJECT_HPP

#include <functional>
#include "GameObject.hpp"
#include "MenuState.hpp"

namespace ds {
    class MenuObject : public GameObject {
    protected:
        MenuState state;
        std::function<void()> actionPressed;
        std::function<void()> actionReleased;
        std::function<void()> actionMoved;

    public:
        using GameObject::GameObject;

        MenuState getState() const;
        std::function<void()> getActionPressed();
        std::function<void()> getActionReleased();
        std::function<void()> getActionMoved();

        void setState(MenuState state);
        void setActionPressed(std::function<void()> func);
        void setActionReleased(std::function<void()> func);
        void setActionMoved(std::function<void()> func);
    };
}

#endif // DS_MENU_OBJECT_HPP
