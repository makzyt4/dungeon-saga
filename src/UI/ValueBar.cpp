#include "../../include/UI/ValueBar.hpp"

void ds::ValueBar::setColor(const sf::Color& color) {
    this->color = color;
}

void ds::ValueBar::setValue(RegeneratedValue* value) {
    this->value = value;
}

void ds::ValueBar::draw() {
    sf::Texture* texture = loader->getTexture("menus.png");
    sf::IntRect spriteRect;

    const int BAR_LENGTH = 10;

    for (int i = 0; i < BAR_LENGTH; i++) {
        if (i == 0) {
            spriteRect = sf::IntRect(0, 72, 8, 16);
        } else if (i == BAR_LENGTH - 1) {
            spriteRect = sf::IntRect(16, 72, 8, 16);
        } else {
            spriteRect = sf::IntRect(8, 72, 8, 16);
        }

        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(spriteRect);
        sprite.setPosition(rect.left + i * 8, rect.top);
        window->draw(sprite);
    }
}