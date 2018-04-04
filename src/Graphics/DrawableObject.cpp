#include "../../include/Graphics/DrawableObject.hpp"

sf::Vector2i ds::DrawableObject::getPosition() const {
    return position;
}

sf::IntRect ds::DrawableObject::getRect() const {
    return rect;
}

void ds::DrawableObject::setPosition(const sf::Vector2i& position) {
    this->position = position;
    rect.left = position.x;
    rect.top = position.y;
}

void ds::DrawableObject::setWindow(sf::RenderWindow* window) {
    this->window = window;
}

void ds::DrawableObject::setLoader(ds::ResourceLoader* loader) {
    this->loader = loader;
}

void ds::DrawableObject::setRect(const sf::IntRect& rect) {
    this->rect = rect;
}
