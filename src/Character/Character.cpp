#include "../../include/Character/Character.hpp"

void ds::Character::draw() {
    sf::Sprite sprite = currentAnimation->currentSprite();
    sprite.setPosition(position.x, position.y);
    window->draw(sprite);
}

void ds::Character::jump() {
    if (onGround) {
        velocity.y = -(2 + agility / 100.0f);
    }
}

void ds::Character::update() {
    currentAnimation->play();
    setPosition(sf::Vector2f(position.x + velocity.x,
                             position.y + velocity.y));
}

float ds::Character::getSpeed() {
    return 1 + agility / 30.0f;
}
