#include "../include/TextButton.hpp"

std::string ds::TextButton::getText() {
    return text;
}

sf::Vector2i ds::TextButton::getSize() {
    return size;
}

void ds::TextButton::setText(std::string text) {
    this->text = text;
}

void ds::TextButton::setSize(sf::Vector2i size) {
    this->size = size;
    rect.width = 8 * size.x;
    rect.height = 8 * size.y;
}

void ds::TextButton::init() {
    actionMoved = [](){};
    actionPressed = [](){};
    actionReleased = [](){};
    texture = loader->getTexture("menus.png");
    text = "";
}

void ds::TextButton::setPosition(int x, int y) {
    rect.left = x;
    rect.top = y;
}

void ds::TextButton::draw(sf::RenderWindow* window) {
    sf::IntRect spriteRect;

    int offset = 0;

    if (state == MenuState::Highlighted) {
        offset = 1;
    } else if (state == MenuState::Clicked) {
        offset = 2;
    }

    for (int j = 0; j < size.y; j++) {
        for (int i = 0; i < size.x; i++) {
            if (i == 0) {
                if (j == 0) {
                    spriteRect = sf::IntRect(0, offset * 24, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(0, 16 + offset * 24, 8, 8);
                } else {
                    spriteRect = sf::IntRect(0, 8 + offset * 24, 8, 8);
                }
            } else if (i == size.x - 1) {
                if (j == 0) {
                    spriteRect = sf::IntRect(16, offset * 24, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(16, 16 + offset * 24, 8, 8);
                } else {
                    spriteRect = sf::IntRect(16, 8 + offset * 24, 8, 8);
                }
            } else {
                if (j == 0) {
                    spriteRect = sf::IntRect(8, offset * 24, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(8, 16 + offset * 24, 8, 8);
                } else {
                    spriteRect = sf::IntRect(8, 8 + offset * 24, 8, 8);
                }
            }

            sf::Sprite sprite;
            sprite.setTexture(*texture);

            sprite.setTextureRect(spriteRect);
            sprite.setPosition(rect.left + i * 8, rect.top + j * 8);
            window->draw(sprite);
        }
    }


    Text text;
    text.setString(this->text);
    text.setPosition(sf::Vector2i(
                     rect.left + (rect.width - text.getSize().x) / 2,
                     rect.top + (rect.height - text.getSize().y) / 2));

    text.draw(window);

}
