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
