#include "../../include/Character/PlayerCharacter.hpp"

void ds::PlayerCharacter::init() {
    strength = 1;
    agility = 1;
    intelligence = 1;
    onGround = false;
    climbing = false;

    health = RegeneratedValue(0, 10, 10);
    health.setRegeneration(0);
    health.setRegenerationTime(sf::seconds(5));

    stamina = RegeneratedValue(0, 10, 10);
    stamina.setRegeneration(1);
    stamina.setRegenerationTime(sf::seconds(1));

    magicka = RegeneratedValue(0, 10, 10);
    magicka.setRegeneration(0);
    magicka.setRegenerationTime(sf::seconds(5));

    experience = RegeneratedValue(0, 0, 100);

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
    direction = Direction::Right;

    stepBuffer = loader->getSoundBuffer("step.ogg");

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

void ds::PlayerCharacter::handleKeys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= getAcceleration();
        direction = Direction::Left;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += getAcceleration();
        direction = Direction::Right;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        jump();
    }
}