#include "../../include/Block/BlockLadder.hpp"

void ds::BlockLadder::draw() {
    sf::Texture* texture = loader->getTexture("blocks.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(48, 48, 16, 16));
    window->draw(sprite);
}

bool ds::BlockLadder::isCollidable() const {
    return false;
}

bool ds::BlockLadder::isDestructible() const {
    return false;
}

bool ds::BlockLadder::isClimbable() const {
    return true;
}
