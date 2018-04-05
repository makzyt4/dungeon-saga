#include "../../include/Block/BlockTorch.hpp"

void ds::BlockTorch::init() {
    rect.width = 16;
    rect.height = 16;
    sf::Texture* texture = loader->getTexture("blocks.png");
    animation.setSpriteSheet(texture);
    animation.setFrameTime(sf::seconds(0.5));
    animation.addFrame(sf::IntRect(0, 32, 16, 16));
    animation.addFrame(sf::IntRect(0, 48, 16, 16));
    animation.addFrame(sf::IntRect(16, 32, 16, 16));
    animation.addFrame(sf::IntRect(16, 48, 16, 16));
}

void ds::BlockTorch::draw() {
    sf::Sprite sprite = animation.currentSprite();
    sprite.setPosition(rect.left, rect.top);
    window->draw(sprite);
}

bool ds::BlockTorch::isCollidable() const {
    return false;
}

bool ds::BlockTorch::isDestructible() const {
    return false;
}

void ds::BlockTorch::update() {
    animation.play();
}
