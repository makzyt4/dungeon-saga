#include "../../include/Block/BlockWindow.hpp"

void ds::BlockWindow::init() {
    rect.width = 16;
    rect.height = 32;
}

void ds::BlockWindow::draw() {
    sf::Texture* texture = loader->getTexture("blocks.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(rect.left, rect.top);
    sprite.setTextureRect(sf::IntRect(32, 32, 16, 32));
    window->draw(sprite);
}

bool ds::BlockWindow::isCollidable() const {
    return false;
}

bool ds::BlockWindow::isDestructible() const {
    return false;
}
