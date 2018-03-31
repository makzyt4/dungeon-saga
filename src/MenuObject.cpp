#include "../include/MenuObject.hpp"

ds::MenuState ds::MenuObject::getState() const {
    return state;
}

void ds::MenuObject::setState(ds::MenuState state) {
    this->state = state;
}
