#include "../../include/Character/Character.hpp"

void ds::Character::draw() {
    sf::Sprite sprite = currentAnimation->currentSprite();
    sprite.setPosition(position.x, position.y);
    window->draw(sprite);
}

void ds::Character::jump() {
    if (onGround) {
        velocity.y = -(2 + agility / 100.0f);
        onGround = false;
    }
}

void ds::Character::update() {
    currentAnimation->play();
    setPosition(sf::Vector2f(position.x + velocity.x,
                             position.y + velocity.y));

    if (!onGround) {
        velocity.y += 0.12;
    }
}

void ds::Character::collide(std::vector<ds::Block*>* blocks) {
    sf::Vector2f tmpPosition = position;
    onGround = false;

    for (Block* block : *blocks) {
        if (!block->isCollidable()) {
            continue;
        }

        sf::IntRect tmpRect;

        // If block on the ground
        tmpRect = rect;
        tmpRect.top += fabs(velocity.y + 1);

        if (block->getRect().intersects(tmpRect) && velocity.y >= 0) {
            velocity.y = 0;
            position.y = tmpPosition.y;
            onGround = true;
        }

        // If block above
        tmpRect = rect;
        tmpRect.top -= fabs(velocity.y + 1);

        if (block->getRect().intersects(tmpRect) && velocity.y < 0) {
            position.y = tmpPosition.y;
            velocity.y = fabs(velocity.y);
        }

        // If block on the left
        tmpRect = rect;
        tmpRect.left -= fabs(velocity.x) + 1;

        if (block->getRect().intersects(tmpRect) && velocity.x < 0) {
            position.x = tmpPosition.x - velocity.x;
            velocity.x = 0;
        }

        // If block on the right
        tmpRect = rect;
        tmpRect.left += fabs(velocity.x) + 1;

        if (block->getRect().intersects(tmpRect) && velocity.x > 0) {
            position.x = tmpPosition.x - velocity.x;
            velocity.x = 0;
        }
    }
}

float ds::Character::getSpeed() {
    return 1 + agility / 30.0f;
}
