#ifndef DS_UI_LAYOUT_HPP
#define DS_UI_LAYOUT_HPP

#include "Node.hpp"

namespace ds {
    class Layout {
    private:
        std::vector<Node*> elements;
    public:
        void addElement(Node* element);
        void listenToAll(sf::Event* event);
        void drawAll(sf::RenderWindow* window);
    };
}

#endif // DS_UI_LAYOUT_HPP
