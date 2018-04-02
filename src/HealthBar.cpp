#include "../include/HealthBar.hpp"

void ds::HealthBar::init() {
    actionMoved = [](){};
    actionPressed = [](){};
    actionReleased = [](){};
    texture = loader->getTexture("menus.png");
}

void ds::HealthBar::setPosition(int x, int y) {
    rect.left = x;
    rect.top = y;
}

void ds::HealthBar::draw(sf::RenderWindow* window) {
    sf::RectangleShape rectShape;
    rectShape.setPosition(rect.left, rect.top);
    rectShape.setSize(sf::Vector2f(24, 8));
    rectShape.setFillColor(sf::Color::Red);
    window->draw(rectShape);

    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 72, 24, 8));
    sprite.setPosition(rect.left, rect.top);
    window->draw(sprite);
}
