#include "../../include/Game/Block.hpp"

void ds::Block::init() {
    rect.width = 16;
    rect.height = 16;
}

sf::IntRect ds::Block::getRect() const {
    return rect;
}

void ds::Block::setPosition(const sf::Vector2i& position) {
    this->position = position;
    rect.left = position.x;
    rect.top = position.y;
}

void ds::Block::setRect(const sf::IntRect& rect) {
    this->rect = rect;
}
