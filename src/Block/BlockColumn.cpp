#include "../../include/Block/BlockColumn.hpp"

void ds::BlockColumn::init() {
    rect.width = 16;
    rect.height = 32;
}

void ds::BlockColumn::draw() {
    sf::Texture* texture = loader->getTexture("blocks.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(48, 0, 16, 32));
    window->draw(sprite);
}

bool ds::BlockColumn::isCollidable() const {
    return false;
}

bool ds::BlockColumn::isDestructible() const {
    return false;
}
