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

    sf::RectangleShape shape;
    shape.setFillColor(color);
    shape.setPosition(rect.left, rect.top);
    shape.setSize(sf::Vector2f(8 * BAR_LENGTH * value->fillRatio(), 8));
    window->draw(shape);

    for (int i = 0; i < BAR_LENGTH; i++) {
        if (i == 0) {
            spriteRect = sf::IntRect(0, 72, 8, 8);
        } else if (i == BAR_LENGTH - 1) {
            spriteRect = sf::IntRect(16, 72, 8, 8);
        } else {
            spriteRect = sf::IntRect(8, 72, 8, 8);
        }

        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(spriteRect);
        sprite.setPosition(rect.left + i * 8, rect.top);
        window->draw(sprite);
    }

    std::string textValue = std::to_string(value->getValue()) + "/" + std::to_string(value->getMax());

    ds::Text text;
    text.setWindow(window);
    text.setString(textValue);
    text.setPosition(sf::Vector2f(
                     1 + rect.left + (BAR_LENGTH * 8 - text.getSize().x) / 2,
                     1 + rect.top));
    text.setColor(sf::Color::Black);
    text.draw();
    text.setPosition(sf::Vector2f(
                     rect.left + (BAR_LENGTH * 8 - text.getSize().x) / 2,
                     rect.top));
    text.setColor(sf::Color::White);
    text.draw();
}