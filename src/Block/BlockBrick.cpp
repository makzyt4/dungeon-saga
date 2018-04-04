#include "../../include/Block/BlockBrick.hpp"

void ds::BlockBrick::draw() {
    sf::Texture* texture = loader->getTexture("blocks.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    window->draw(sprite);
}

bool ds::BlockBrick::isCollidable() {
    return true;
}

bool ds::BlockBrick::isDestructible() {
    return false;
}
