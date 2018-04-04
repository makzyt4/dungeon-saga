#include "../../include/UI/Layout.hpp"

void ds::Layout::addElement(Node* element) {
    elements.push_back(element);
}

void ds::Layout::listenToAll(sf::Event* event) {
    for (Node* element : elements) {
        element->listen(event);
    }
}
