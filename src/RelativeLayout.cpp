#include "../include/RelativeLayout.hpp"

ds::RelativeLayout::RelativeLayout(ds::ResourceLoader* loader) {
    this->loader = loader;
    selected = NULL;
}

void ds::RelativeLayout::addElement(ds::MenuObject* element) {
    element->setLoader(loader);
    element->init();
    elements.push_back(element);
}

void ds::RelativeLayout::onMouseMove(MenuObject* object, sf::Event* event,
                                     std::function<void()> func) {
    if (selected == object) {
        return;
    }

    int x = event->mouseMove.x;
    int y = event->mouseMove.y;

    if (event->type == sf::Event::MouseMoved
        && object->getRect().contains(x, y)) {
        object->setState(ds::MenuState::Highlighted);
        func();
    }
}

void ds::RelativeLayout::onMouseLeftPressed(MenuObject* object, sf::Event* event,
                                        std::function<void()> func) {
    if (event->mouseButton.button != sf::Mouse::Left) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;

    if (event->type == sf::Event::MouseButtonPressed
        && object->getRect().contains(x, y)) {
        object->setState(ds::MenuState::Clicked);
        selected = object;
        func();
    }
}

void ds::RelativeLayout::onMouseLeftReleased(MenuObject* object, sf::Event* event,
                                             std::function<void()> func) {
    if (event->mouseButton.button != sf::Mouse::Left) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;
    object->setState(ds::MenuState::Normal);

    if (event->type == sf::Event::MouseButtonPressed
        && object->getRect().contains(x, y)) {
        if (selected == object) {
            func();
        }
    } else {
        selected = NULL;
    }
}
