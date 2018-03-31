#include "../include/Screen.hpp"

ds::Screen::Screen(sf::RenderWindow* window, ResourceLoader* loader) {
    this->window = window;
    this->loader = loader;
}

ds::ExitCode ds::Screen::getCode() {
    return code;
}

void ds::Screen::onClick(ds::MenuObject* object, sf::Event* event,
                         std::function<void()> func) {
    int x = event->mouseButton.x;
    int y = event->mouseButton.y;

    if (event->type == sf::Event::MouseButtonPressed
        && object->getRect().contains(x, y)) {
        func();
    }
}

void ds::Screen::onMouseMove(ds::MenuObject* object, sf::Event* event,
                             std::function<void()> func) {
    int x = event->mouseMove.x;
    int y = event->mouseMove.y;

    if (event->type == sf::Event::MouseMoved
        && object->getRect().contains(x, y)) {
        func();
    }
}
