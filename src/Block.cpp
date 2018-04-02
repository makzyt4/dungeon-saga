#include "../include/Block.hpp"

bool ds::Block::isDestructible() const {
    return destructible;
}

void ds::Block::setDestructible(const bool& destructible) {
    this->destructible = destructible;
}
