#ifndef DS_UI_BUTTON_HPP
#define DS_UI_BUTTON_HPP

#include "Node.hpp"
#include "../Graphics/Text.hpp"

namespace ds {
    class Button : public Node {
    private:
        sf::Vector2i size;
        std::string text;
        bool selected;
    public:
        sf::Vector2i getSize() const;
        std::string getText() const;

        void setSize(const sf::Vector2i& size);
        void setText(const std::string& text);

        void draw();
        void init();
        void onMouseHoverAction(sf::Event* event);
        void onMousePressedAction(sf::Event* event);
        void onMouseReleasedAction(sf::Event* event);
    };
}

#endif // DS_UI_BUTTON_HPP
