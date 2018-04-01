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

    if (event->type == sf::Event::MouseMoved) {
        if (object->getRect().contains(x, y)) {
            object->setState(ds::MenuState::Highlighted);
            func();
        } else {
            object->setState(ds::MenuState::Normal);
        }
    }
}

void ds::RelativeLayout::onMouseLeftPressed(MenuObject* object, sf::Event* event,
                                        std::function<void()> func) {
    if (event->mouseButton.button != sf::Mouse::Left) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;

    if (event->type == sf::Event::MouseButtonPressed) {
        if (object->getRect().contains(x, y)
            && object->getState() == ds::MenuState::Normal) {
            object->setState(ds::MenuState::Clicked);
            func();
            selected = object;
        } else {
            object->setState(ds::MenuState::Normal);
        }
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

    if (event->type == sf::Event::MouseButtonPressed) {
        if (object->getRect().contains(x, y)
            && selected == object) {
            func();
        }
    }
}

void ds::RelativeLayout::listenToElements(sf::Event* event) {
    
}
