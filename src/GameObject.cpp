#include "../include/GameObject.hpp"

ds::GameObject::GameObject(ResourceLoader* loader) {
    this->loader = loader;
}

sf::IntRect ds::GameObject::getRect() const {
    return rect;
}
