#include "../../include/Block/BlockBackground.hpp"

void ds::BlockBackground::draw() {
    sf::Texture* texture = loader->getTexture("blocks.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
    window->draw(sprite);
}

bool ds::BlockBackground::isCollidable() const {
    return false;
}

bool ds::BlockBackground::isDestructible() const {
    return false;
}
