#include "../../include/Character/Character.hpp"

void ds::Character::draw() {
    sf::Sprite sprite = currentAnimation->currentSprite();
    sprite.setPosition(position.x, position.y);
    window->draw(sprite);
}

void ds::Character::jump() {
    float velocityY = -(2 + agility / 100.0f);

    if (climbing) {
        velocity.y = velocityY;
        onGround = false;
        return;
    }

    if (onGround && stamina.getValue() >= 3) {
        stamina.addValue(-3);
        velocity.y = -(2 + agility / 100.0f);
        onGround = false;
    }
}

void ds::Character::update() {
    stamina.update();
    health.update();
    magicka.update();

    stepDelay = std::max(0, stepDelay - 1);

    if (velocity.x < -getMaxSpeed()) {
        velocity.x = -getMaxSpeed();
    } else if (velocity.x > getMaxSpeed()) {
        velocity.x = getMaxSpeed();
    }

    currentAnimation->play();

    setPosition(sf::Vector2f(position.x + velocity.x,
                             position.y + velocity.y));

    if (!onGround) {
        velocity.y += 0.12;
    }

    if (fabs(velocity.x) > 0.1) {
        currentAnimation = direction == Direction::Left ?
                           &movingLeft :
                           &movingRight;
        if (stepDelay == 0 && onGround) {
            sf::Sound* sound = new sf::Sound();
            sound->setBuffer(*stepBuffer);
            sound->play();
            stepDelay = 40;
        }
    } else {
        velocity.x = 0;
        currentAnimation = direction == Direction::Left ?
                           &standingLeft :
                           &standingRight;
    }
    velocity.x *= 0.9;
}

void ds::Character::collide(std::vector<ds::Block*>* blocks) {
    sf::Vector2f tmpPosition = position;
    onGround = false;
    climbing = false;

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
        }

        // If block on the right
        tmpRect = rect;
        tmpRect.left += fabs(velocity.x) + 1;

        if (block->getRect().intersects(tmpRect) && velocity.x > 0) {
            position.x = tmpPosition.x - velocity.x;
        }
    }

    for (Block* block : *blocks) {
        if (rect.intersects(block->getRect()) && block->isClimbable()) {
            climbing = true;
            break;
        }
    }
}

float ds::Character::getAcceleration() {
    return agility / 10.0f;
}

float ds::Character::getMaxSpeed() {
    return 3 + agility / 10.0f;
}

sf::Vector2f ds::Character::getCenter() {
    return sf::Vector2f(rect.left + rect.width / 2.0f,
                        rect.top + rect.height / 2.0f);
}
