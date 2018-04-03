#include "../include/HealthBar.hpp"

int ds::HealthBar::getWidth() const {
    return width;
}

void ds::HealthBar::setWidth(const int& width) {
    this->width = width;
}

void ds::HealthBar::init() {
    texture = loader->getTexture("menus.png");
    width = 5;
    actionMoved = [](){};
    actionPressed = [](){};
    actionReleased = [](){};
}

void ds::HealthBar::setValue(const int& value) {
    this->value = value;
}

void ds::HealthBar::setPosition(int x, int y) {
    rect.left = x;
    rect.top = y;
}

void ds::HealthBar::setValues(const int& min, const int& max) {
    minValue = min;
    maxValue = max;
    value = max;
}

void ds::HealthBar::draw(sf::RenderWindow* window) {
    sf::RectangleShape rectShape;
    rectShape.setPosition(rect.left, rect.top);
    rectShape.setSize(sf::Vector2f(8 * (width + 2), 8));
    rectShape.setFillColor(sf::Color::Red);
    window->draw(rectShape);

    sf::Sprite sprite1;
    sprite1.setTexture(*texture);
    sprite1.setTextureRect(sf::IntRect(0, 72, 8, 8));
    sprite1.setPosition(rect.left, rect.top);
    window->draw(sprite1);

    for (int i = 1; i <= width; i++) {
        sf::Sprite sprite2 = sprite1;
        sprite2.setTextureRect(sf::IntRect(8, 72, 8, 8));
        sprite2.setPosition(rect.left + i * 8, rect.top);
        window->draw(sprite2);
    }

    sf::Sprite sprite3;
    sprite3.setTexture(*texture);
    sprite3.setTextureRect(sf::IntRect(16, 72, 8, 8));
    sprite3.setPosition(rect.left + (width + 1) * 8, rect.top);
    window->draw(sprite3);
}
