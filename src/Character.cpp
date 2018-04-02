#include "../include/Character.hpp"

sf::IntRect ds::Character::getRect() {
    return rect;
}

ds::Animation* ds::Character::getCurrentAnimation() {
    return currentAnimation;
}

void ds::Character::jump() {
    if (onGround) {
        velocity.y -= jumpHeight;
    }
}

sf::Vector2i ds::Character::getCenter() {
    sf::Vector2i center;
    center.x = rect.left + rect.width / 2;
    center.y = rect.top + rect.height / 2;

    return center;
}
