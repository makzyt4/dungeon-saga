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

    movingRight.setFrameTime(sf::seconds(0.2));
    movingRight.setSpriteSheet(texture);
    movingRight.addFrame(sf::IntRect(64, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(96, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(128, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(160, 0, 32, 32));
    movingRight.addFrame(sf::IntRect(192, 0, 32, 32));

    movingLeft.setFrameTime(sf::seconds(0.2));
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
