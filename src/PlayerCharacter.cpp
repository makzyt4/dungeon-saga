#include "../include/PlayerCharacter.hpp"

void ds::PlayerCharacter::init(ds::ResourceLoader* loader) {
    direction = ds::LookingDirection::Right;
    rect = sf::IntRect(0, 0, 12, 31);
    health = sf::Vector2i(5, 5);
    baseAttackDmg = sf::Vector2i(1, 2);
    currentAttackDmg = baseAttackDmg;
    level = 1;
    speed = 1.f;

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
    movingLeft.addFrame(sf::IntRect(128, 32, 32, 32));
    movingLeft.addFrame(sf::IntRect(160, 32, 32, 32));
    movingLeft.addFrame(sf::IntRect(192, 32, 32, 32));

    currentAnimation = &standingRight;
}

void ds::PlayerCharacter::update() {
    currentAnimation->play();

    if (velocity.x != 0) { // If moving
        currentAnimation = direction == ds::LookingDirection::Left ?
                           &movingLeft : &movingRight;
    } else { // If standing
        currentAnimation = direction == ds::LookingDirection::Left ?
                           &standingLeft : &standingRight;
    }

    setPosition(position.x + velocity.x, position.y + velocity.y);
}

void ds::PlayerCharacter::draw(sf::RenderWindow* window) {
    sf::Sprite sprite = currentAnimation->currentSprite();

    sprite.setPosition(position.x, position.y);

    window->draw(sprite);
}

void ds::PlayerCharacter::setPosition(int x, int y) {
    position.x = x;
    position.y = y;

    rect.left = x + 10;
    rect.top = y + 1;
}

void ds::PlayerCharacter::handleKeys(sf::Event* event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x = -speed;
        direction = ds::LookingDirection::Left;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x = speed;
        direction = ds::LookingDirection::Right;
    } else {
        velocity.x *= 0.9;
    }
}

bool ds::PlayerCharacter::isCollidable() {
    return false;
}
