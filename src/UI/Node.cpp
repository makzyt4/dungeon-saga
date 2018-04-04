#include "../../include/UI/Node.hpp"

ds::Node::Node() {
    state = MenuState::Normal;
    mouseHoverAction = [](){};
    mousePressedAction = [](){};
    mouseReleasedAction = [](){};
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
