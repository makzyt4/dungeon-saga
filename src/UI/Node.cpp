#include "../../include/UI/Node.hpp"

ds::Node::Node() {
    state = MenuState::Normal;
    mouseHoverAction = [](){};
    mousePressedAction = [](){};
    mouseReleasedAction = [](){};
}

sf::IntRect ds::Node::getRect() const {
    return rect;
}

void ds::Node::setPosition(const sf::Vector2i& position) {
    this->position = position;
    rect.left = position.x;
    rect.top = position.y;
}

void ds::Node::setRect(const sf::IntRect& rect) {
    this->rect = rect;
}

void ds::Node::listen(sf::Event* event) {
    onMouseHoverAction(event);
    onMouseReleasedAction(event);
    onMousePressedAction(event);
}

void ds::Node::setOnMouseHoverAction(std::function<void()> action) {
    mouseHoverAction = action;
}

void ds::Node::setOnMousePressedAction(std::function<void()> action) {
    mousePressedAction = action;
}

void ds::Node::setOnMouseReleasedAction(std::function<void()> action) {
    mouseReleasedAction = action;
}
