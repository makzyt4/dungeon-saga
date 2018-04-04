#include "../../include/UI/Button.hpp"

void ds::Button::init() {
    text = "";
}

sf::Vector2i ds::Button::getSize() const {
    return size;
}

std::string ds::Button::getText() const {
    return text;
}

void ds::Button::setSize(const sf::Vector2i& size) {
    this->size = sf::Vector2i(size.x, size.y);
    rect.width = size.x * 8;
    rect.height = size.y * 8;
}

void ds::Button::setText(const std::string& text) {
    this->text = text;
}

void ds::Button::draw() {
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

    Text text;
    text.setWindow(window);
    text.setString(this->text);
    text.setPosition(sf::Vector2i(
                     rect.left + (rect.width - text.getSize().x) / 2,
                     rect.top + (rect.height - text.getSize().y) / 2));

    text.draw();
}

void ds::Button::onMouseHoverAction(sf::Event* event) {

}

void ds::Button::onMousePressedAction(sf::Event* event) {

}

void ds::Button::onMouseReleasedAction(sf::Event* event) {

}
