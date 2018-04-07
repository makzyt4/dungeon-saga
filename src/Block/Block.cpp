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

sf::Vector2f ds::Block::getCenter() {
    return sf::Vector2f(rect.left + 8,
                        rect.top + 8);
}
