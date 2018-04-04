#ifndef DS_UI_NODE_HPP
#define DS_UI_NODE_HPP

#include <functional>
#include <SFML/Graphics.hpp>
#include "../Graphics/DrawableObject.hpp"

namespace ds {
    class Node : public DrawableObject {
    protected:
        sf::Event* event;
        sf::IntRect rect;

        std::function<void()> mouseHoverAction;
        std::function<void()> mousePressedAction;
        std::function<void()> mouseReleasedAction;
    public:
        Node();

        sf::IntRect getRect() const;

        void setPosition(const sf::Vector2i& position);
        void setRect(const sf::IntRect& rect);

        void listen(sf::Event* event);

        virtual void init() = 0;
        virtual void setOnMouseHoverAction(std::function<void()> action) = 0;
        virtual void setOnMousePressedAction(std::function<void()> action) = 0;
        virtual void setOnMouseReleasedAction(std::function<void()> action) = 0;
    };
}

#endif // DS_UI_NODE_HPP
