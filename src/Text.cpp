#include "../include/Text.hpp"

ds::Text::Text() {
    fontSize = 1;
    color = sf::Color::White;
    width = 0;
    height = 0;
    currentWidth = 0;
}

std::string ds::Text::getString() const {
    return string;
}

sf::Vector2i ds::Text::getPosition() const {
    return position;
}

std::size_t ds::Text::getFontSize() const {
    return fontSize;
}

sf::Vector2i ds::Text::getSize() const {
    sf::Vector2i size;
    size.x = width;
    size.y = height;
    return size;
}

void ds::Text::setString(const std::string& string) {
    this->string = string;
}

void ds::Text::setPosition(const sf::Vector2i& position) {
    this->position = position;
}

void ds::Text::setFontSize(const std::size_t fontSize) {
    this->fontSize = fontSize;
}

void ds::Text::setColor(const sf::Color& color) {
    this->color = color;
}

void ds::Text::draw(sf::RenderWindow* window) {
    int x = position.x;
    int y = position.y;

    for (char& c : string) {
        if (c == '\n') {
            x = position.x;
            y += 8 * fontSize;
            height += 8 * fontSize;
            currentWidth = 0;
        } else if (c == '\r') {
            x = position.x;
            currentWidth = 0;
        } else {
            font.drawCharacter(window, c, sf::Vector2i(x, y), fontSize, color);
            x += 8 * fontSize;
            currentWidth += 8 * fontSize;
            width = std::max((int&) currentWidth, width);
        }
    }
}
