#include "../../include/UI/Panel.hpp"

void ds::Panel::init() {
    // Nothing to do here...
}

sf::Vector2i ds::Panel::getSize() const {
    return size;
}

void ds::Panel::setSize(const sf::Vector2i& size) {
    this->size = size;
    rect.width = size.x * 8;
    rect.height = size.y * 8;
}

void ds::Panel::draw() {
    sf::Texture* texture = loader->getTexture("menus.png");
    sf::IntRect spriteRect;

    for (int j = 0; j < size.y; j++) {
        for (int i = 0; i < size.x; i++) {
            if (i == 0) {
                if (j == 0) {
                    spriteRect = sf::IntRect(0, 0, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(0, 16, 8, 8);
                } else {
                    spriteRect = sf::IntRect(0, 8, 8, 8);
                }
            } else if (i == size.x - 1) {
                if (j == 0) {
                    spriteRect = sf::IntRect(16, 0, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(16, 16, 8, 8);
                } else {
                    spriteRect = sf::IntRect(16, 8, 8, 8);
                }
            } else {
                if (j == 0) {
                    spriteRect = sf::IntRect(8, 0, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(8, 16, 8, 8);
                } else {
                    spriteRect = sf::IntRect(8, 8, 8, 8);
                }
            }

            sf::Sprite sprite;
            sprite.setTexture(*texture);

            sprite.setTextureRect(spriteRect);
            sprite.setPosition(rect.left + i * 8, rect.top + j * 8);
            window->draw(sprite);
        }
    }
}
