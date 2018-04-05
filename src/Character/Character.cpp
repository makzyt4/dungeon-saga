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
    } else {
        velocity.y = 0;
    }
}

void ds::Character::collide(std::vector<ds::Block*>* blocks) {
    sf::IntRect tmpRect;
    onGround = false;

    for (Block* block : *blocks) {
        if (!block->isCollidable()) {
            continue;
        }

        // Block above
        tmpRect = rect;
        tmpRect.top -= abs(velocity.x);

        if (tmpRect.intersects(block->getRect())) {
            setPosition(sf::Vector2f(position.x, position.y + 1));
            velocity.y *= -1;
        }

        // Block below
        tmpRect = rect;
        tmpRect.top += 1 + abs(velocity.y);

        if (tmpRect.intersects(block->getRect())) {
            velocity.y = 0;
            setPosition(sf::Vector2f(position.x, position.y));
            onGround = true;
        }

        // Block to the left
        tmpRect = rect;
        tmpRect.left -= 1 + abs(velocity.x);

        if (tmpRect.intersects(block->getRect())) {
            setPosition(sf::Vector2f(position.x + 1, position.y));
            velocity.x = 0;
        }

        // Block to the right
        tmpRect = rect;
        tmpRect.left += 1 + abs(velocity.x);

        if (tmpRect.intersects(block->getRect())) {
            setPosition(sf::Vector2f(position.x - 1, position.y));
            velocity.x = 0;
        }
    }
}

float ds::Character::getSpeed() {
    return 1 + agility / 30.0f;
}
