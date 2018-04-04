#ifndef DS_UI_NODE_HPP
#define DS_UI_NODE_HPP

#include <functional>
#include <SFML/Graphics.hpp>

namespace ds {
    class Node {
    protected:
        sf::IntRect rect;
        sf::Event* event;

        std::function<void()> mouseHoverAction;
        std::function<void()> mousePressedAction;
        std::function<void()> mouseReleasedAction;
    public:
        Node();

        sf::IntRect getRect() const;

        void setRect(const sf::IntRect& rect);

        void listen(sf::Event* event);
        virtual void setOnMouseHoverAction(std::function<void()> action) = 0;
        virtual void setOnMousePressedAction(std::function<void()> action) = 0;
        virtual void setOnMouseReleasedAction(std::function<void()> action) = 0;
    };
}

#endif // DS_UI_NODE_HPP
