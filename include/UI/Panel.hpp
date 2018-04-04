#ifndef DS_UI_PANEL_HPP
#define DS_UI_PANEL_HPP

#include "Node.hpp"

namespace ds {
    class Panel : public Node {
    private:
        sf::Vector2i size;
    public:
        sf::Vector2i getSize() const;

        void setSize(const sf::Vector2i& size);

        void draw();
        void init();
        void setOnMouseHoverAction(std::function<void()> action);
        void setOnMousePressedAction(std::function<void()> action);
        void setOnMouseReleasedAction(std::function<void()> action);
    };
}

#endif // DS_UI_PANEL_HPP
