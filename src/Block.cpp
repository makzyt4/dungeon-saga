#include "../include/Block.hpp"

bool ds::Block::isDestructible() const {
    return destructible;
}

bool ds::Block::isDestroyed() const {
    return destroyed;
}

void ds::Block::setDestructible(const bool& destructible) {
    this->destructible = destructible;
}

void ds::Block::setDestroyed(const bool& destroyed) {
    this->destroyed = destroyed;
}

void ds::Block::setPosition(int x, int y) {
    rect.left = x;
    rect.top = y;
    rect.width = 16;
    rect.height = 16;
}
