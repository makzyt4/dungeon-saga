#include "../include/BrickDoorBackground.hpp"

void ds::BrickDoorBackground::init() {
    texture = loader->getTexture("blocks.png");
}

void ds::BrickDoorBackground::draw(sf::RenderWindow* window) {
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(16, 0, 16, 32));
    window->draw(sprite);
}

bool ds::BrickDoorBackground::isCollidable() {
    return false;
}

void ds::BrickDoorBackground::setPosition(int x, int y) {
    rect.left = x;
    rect.top = y;
    rect.width = 16;
    rect.height = 32;
}
