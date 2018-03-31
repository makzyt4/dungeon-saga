#include "../include/GameObject.hpp"

ds::GameObject::GameObject() {
    this->loader = NULL;
}

ds::GameObject::GameObject(ResourceLoader* loader) {
    this->loader = loader;
}

sf::IntRect ds::GameObject::getRect() const {
    return rect;
}

void ds::GameObject::setLoader(ResourceLoader* loader) {
    this->loader = loader;
}
