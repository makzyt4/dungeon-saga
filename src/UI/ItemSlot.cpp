#include "../../include/UI/ItemSlot.hpp"

void ds::ItemSlot::init() {
    selected = false;
}

void ds::ItemSlot::draw() {
    sf::Color outlineColor = selected ? sf::Color::White : sf::Color::Blue;

    sf::RectangleShape outlineShape;
    outlineShape.setOutlineColor(outlineColor);
    outlineShape.setOutlineThickness(2);
    outlineShape.setFillColor(sf::Color(0, 0, 0, 0));
    outlineShape.setPosition(rect.left, rect.top);
    outlineShape.setSize(sf::Vector2f(32, 32));

    window->draw(outlineShape);

    if (item != NULL) {
        item->sprite.setPosition(rect.left, rect.top);
        window->draw(item->sprite);
    }
}

void ds::ItemSlot::onMouseHoverAction(sf::Event* event) {
}

void ds::ItemSlot::onMousePressedAction(sf::Event* event) {
}

void ds::ItemSlot::onMouseReleasedAction(sf::Event* event) {
}
