#ifndef DS_UI_NODE_HPP
#define DS_UI_NODE_HPP

#include <functional>
#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"
#include "../Enum/MenuState.hpp"

namespace ds {
    class Node : public DrawableObject {
    protected:
        MenuState state;

        std::function<void()> mouseHoverAction;
        std::function<void()> mousePressedAction;
        std::function<void()> mouseReleasedAction;
    public:
        Node();

        void listen(sf::Event* event);

        void setOnMouseHoverAction(std::function<void()> action);
        void setOnMousePressedAction(std::function<void()> action);
        void setOnMouseReleasedAction(std::function<void()> action);

        virtual void init() = 0;
        virtual void onMouseHoverAction(sf::Event* event) = 0;
        virtual void onMousePressedAction(sf::Event* event) = 0;
        virtual void onMouseReleasedAction(sf::Event* event) = 0;
    };
}

#endif // DS_UI_NODE_HPP
