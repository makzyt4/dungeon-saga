#include "../include/MenuObject.hpp"

ds::MenuState ds::MenuObject::getState() const {
    return state;
}

std::function<void()> ds::MenuObject::getActionPressed() {
    return actionPressed;
}

std::function<void()> ds::MenuObject::getActionReleased() {
    return actionReleased;
}

std::function<void()> ds::MenuObject::getActionMoved() {
    return actionMoved;
}

void ds::MenuObject::setState(ds::MenuState state) {
    this->state = state;
}

void ds::MenuObject::setActionPressed(std::function<void()> func) {
    actionPressed = func;
}

void ds::MenuObject::setActionReleased(std::function<void()> func) {
    actionReleased = func;
}

void ds::MenuObject::setActionMoved(std::function<void()> func) {
    actionMoved = func;
}

bool ds::MenuObject::isCollidable() {
    return false;
}
