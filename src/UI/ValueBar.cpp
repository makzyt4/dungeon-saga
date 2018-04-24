#include "../../include/UI/ValueBar.hpp"

void ds::ValueBar::setPosition(const sf::Vector2f& position) {
    this->position = position;
}

void ds::ValueBar::setColor(const sf::Color& color) {
    this->color = color;
}

void ds::ValueBar::setValue(RegeneratedValue* value) {
    this->value = value;
}

void ds::ValueBar::draw() {
    
}