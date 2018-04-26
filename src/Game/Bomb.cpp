#include "../../include/Game/Bomb.hpp"

void ds::Bomb::init() {
    exploded = false;
}

void ds::Bomb::draw() {
    if (!exploded) {
        sf::Texture* texture = loader->getTexture("objects.png");
        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.setPosition(rect.left, rect.top);
        window->draw(sprite);
    }
}

void ds::Bomb::update() {
    if (bombClock.getElapsedTime() > sf::seconds(5)) {
        exploded = true;
    }
}