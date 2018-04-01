#include "../include/PlayerCharacter.hpp"

void ds::PlayerCharacter::init() {
    direction = ds::LookingDirection::Right;
    rect = sf::IntRect(0, 0, 12, 31);
    health = sf::Vector2i(5, 5);
    baseAttackDmg = sf::Vector2i(1, 2);
    currentAttackDmg = baseAttackDmg;
    level = 1;
    speed = 1.f;
}

void ds::PlayerCharacter::update(sf::Event* event) {
    currentAnimation->play();
}

void ds::PlayerCharacter::draw(sf::RenderWindow* window) {
    sf::Sprite sprite = currentAnimation->currentSprite();

    sprite.setPosition(position.x, position.y);

    window->draw(sprite);
}
