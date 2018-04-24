#include "../../include/UI/ExperienceBar.hpp"

void ds::ExperienceBar::setValue(RegeneratedValue* value) {
    this->value = value;
}

void ds::ExperienceBar::draw() {
    sf::RectangleShape outlineShape;
    outlineShape.setOutlineColor(sf::Color::White);
    outlineShape.setOutlineThickness(1);
    outlineShape.setFillColor(sf::Color(0, 0, 0, 0));
    outlineShape.setPosition(rect.left, rect.top);
    outlineShape.setSize(sf::Vector2f(80, 4));

    window->draw(outlineShape);
}