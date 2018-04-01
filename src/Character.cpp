#include "../include/Character.hpp"

sf::IntRect ds::Character::getRect() {
    return rect;
}

ds::Animation* ds::Character::getCurrentAnimation() {
    return currentAnimation;
}
