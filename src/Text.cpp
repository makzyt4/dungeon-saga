#include "../include/Text.hpp"

std::string ds::Text::getString() const {
    return string;
}

sf::IntRect ds::Text::getPosition() const {
    return position;
}

std::size_t ds::Text::getSize() const {
    return size;
}

void ds::Text::setString(const std::string& string) {
    this->string = string;
}

void ds::Text::setPosition(const sf::IntRect& position) {
    this->position = position;
}

void ds::Text::setSize(const std::size_t size) {
    this->size = size;
}

void ds::Text::draw(sf::RenderWindow* window) {
    int x = position.left;
    int y = position.top;

    for (char& c : string) {
        if (c == '\n') {
            x = position.left;
            y += 8 * size;
            position.height += 8 * size;
        } else if (c == '\r') {
            y += 8 * size;
        } else {
            font.drawCharacter(window, c, sf::Vector2i(x, y), size, color);
            x += 8 * size;
            position.width += 8 * size;
        }
    }
}
