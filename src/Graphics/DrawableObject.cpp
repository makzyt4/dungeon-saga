#include "../../include/Graphics/DrawableObject.hpp"

sf::Vector2i ds::DrawableObject::getPosition() const {
    return position;
}

void ds::DrawableObject::setPosition(sf::Vector2i) {
    this->position = position;
}

void ds::DrawableObject::setWindow(sf::RenderWindow* window) {
    this->window = window;
}

void ds::DrawableObject::setLoader(ds::ResourceLoader* loader) {
    this->loader = loader;
}
