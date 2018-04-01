#include "../include/Character.hpp"

sf::IntRect ds::Character::getRect() {
    return rect;
}

ds::Animation* ds::Character::getCurrentAnimation() {
    return currentAnimation;
}

void ds::Character::setPosition(int x, int y) {
    position.x = x;
    position.y = y;

    rect.left = x + 10;
    rect.top = y - 31;
}
