#include "../include/BrickBlock.hpp"

void ds::BrickBlock::init() {
    texture = loader->getTexture("menus.png");
}

void ds::BrickBlock::draw(sf::RenderWindow* window) {
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    window->draw(sprite);
}
