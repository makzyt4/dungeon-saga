#include "../../include/Block/BlockBroken.hpp"

void ds::BlockBroken::draw() {
    sf::Texture* texture = loader->getTexture("blocks.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    if (!destroyed) {
        sprite.setTextureRect(sf::IntRect(48, 32, 16, 16));
    } else {
        sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
    }
    window->draw(sprite);
}

bool ds::BlockBroken::isCollidable() const {
    return !destroyed;
}

bool ds::BlockBroken::isDestructible() const {
    return true;
}