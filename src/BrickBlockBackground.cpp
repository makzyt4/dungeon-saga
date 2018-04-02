#include "../include/BrickBlockBackground.hpp"

void ds::BrickBlockBackground::init() {
    texture = loader->getTexture("blocks.png");
}

void ds::BrickBlockBackground::draw(sf::RenderWindow* window) {
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
    window->draw(sprite);
}

bool ds::BrickBlockBackground::isCollidable() {
    return false;
}
