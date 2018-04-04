#include "../../include/UI/Layout.hpp"

void ds::Layout::addElement(Node* element) {
    element->setWindow(window);
    element->setLoader(loader);
    elements.push_back(element);
}

void ds::Layout::listenToAll(sf::Event* event) {
    for (Node* element : elements) {
        element->listen(event);
    }
}

void ds::Layout::drawAll() {
    for (Node* element : elements) {
        sf::Vector2f position = element->getPosition();
        element->setPosition(sf::Vector2f(position.x + this->position.x,
                                          position.y + this->position.y));
        element->draw();
        element->setPosition(position);
    }
}

void ds::Layout::draw() {
    drawAll();
}
