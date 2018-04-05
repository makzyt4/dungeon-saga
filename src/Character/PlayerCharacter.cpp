#include "../../include/Character/PlayerCharacter.hpp"

void ds::PlayerCharacter::init() {
    health = 10;
    maxHealth = 10;
    strength = 1;
    agility = 1;
    intelligence = 1;
    onGround = false;

    sf::Texture* texture = loader->getTexture("hero.png");

    standingRight.setFrameTime(sf::seconds(0.5));
    standingRight.setSpriteSheet(texture);
    standingRight.addFrame(sf::IntRect(0, 0, 32, 32));
    standingRight.addFrame(sf::IntRect(32, 0, 32, 32));

    standingLeft.setFrameTime(sf::seconds(0.5));
    standingLeft.setSpriteSheet(texture);
    standingLeft.addFrame(sf::IntRect(0, 32, 32, 32));
    standingLeft.addFrame(sf::IntRect(32, 32, 32, 32));

    movingRight.setFrameTime(sf::seconds(0.15));
    movingRight.setSpriteSheet(texture);
    movingRight.addFrame(sf::IntRect(64, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(96, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(128, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(160, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(192, 0, 32, 32));

    movingLeft.setFrameTime(sf::seconds(0.15));
    movingLeft.setSpriteSheet(texture);
    movingLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    movingLeft.addFrame(sf::IntRect(96, 32, 32, 32));
    movingLeft.addFrame(sf::IntRect(160, 32, 32, 32));
    movingLeft.addFrame(sf::IntRect(128, 32, 32, 32));
    movingLeft.addFrame(sf::IntRect(192, 32, 32, 32));

    currentAnimation = &standingRight;
    direction = LookingDirection::Right;

    rect.width = 12;
    rect.height = 31;
}

void ds::PlayerCharacter::setPosition(const sf::Vector2f& position) {
    this->position.x = position.x;
    this->position.y = position.y;

    rect.left = position.x + 10;
    rect.top = position.y + 1;
}

bool ds::PlayerCharacter::isCollidable() const {
    return true;
}

bool ds::PlayerCharacter::isFlying() const {
    return false;
}

void ds::PlayerCharacter::handleKeys(sf::Event* event) {
    velocity.x *= 0.9;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x = -getSpeed();
        currentAnimation = &movingLeft;
        direction = LookingDirection::Left;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x = getSpeed();
        currentAnimation = &movingRight;
        direction = LookingDirection::Right;
    }

    if (abs(velocity.x) < 0.1) {
        velocity.x = 0;
        currentAnimation = direction == LookingDirection::Left ?
                           &standingLeft :
                           &standingRight;
    }
}
