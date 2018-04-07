#include "../../include/Block/Block.hpp"

void ds::Block::init() {
    rect.width = 16;
    rect.height = 16;
}

void ds::Block::update() {
}

bool ds::Block::isClimbable() const {
    return false;
}
