#include "../../include/UI/Node.hpp"

ds::Node::Node() {
    mouseHoverAction = [](){};
    mousePressedAction = [](){};
    mouseReleasedAction = [](){};
}

sf::IntRect ds::Node::getRect() const {
    return rect;
}

void ds::Node::setRect(const sf::IntRect& rect) {
    this->rect = rect;
}

void ds::Node::listen(sf::Event* event) {
    this->event = event;
    mouseReleasedAction();
    mouseHoverAction();
    mousePressedAction();
}
