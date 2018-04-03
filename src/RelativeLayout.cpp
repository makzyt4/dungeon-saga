#include "../include/RelativeLayout.hpp"

ds::RelativeLayout::RelativeLayout(sf::RenderWindow* window,
                                   ds::ResourceLoader* loader) {
    this->window = window;
    this->loader = loader;
    selected = NULL;
}

void ds::RelativeLayout::addElement(ds::MenuObject* element) {
    element->setLoader(loader);
    element->init();
    elements.push_back(element);
}

void ds::RelativeLayout::onMouseMoved(MenuObject* object, sf::Event* event,
                                      std::function<void()> func) {
    if (selected == object) {
        return;
    }

    int x = event->mouseMove.x;
    int y = event->mouseMove.y;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Vector2i(x, y));

    if (event->type == sf::Event::MouseMoved) {
        if (object->getRect().contains(mouse.x, mouse.y)) {
            object->setState(ds::MenuState::Highlighted);
            func();
        } else {
            object->setState(ds::MenuState::Normal);
        }
    }
}

void ds::RelativeLayout::onMouseLeftPressed(MenuObject* object,
                                            sf::Event* event,
                                            std::function<void()> func) {
    if (event->mouseButton.button != sf::Mouse::Left) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Vector2i(x, y));

    if (event->type == sf::Event::MouseButtonPressed) {
        if (object->getRect().contains(mouse.x, mouse.y)) {
            sf::SoundBuffer* buffer = loader->getSoundBuffer("click.ogg");
            sf::Sound* sound = new sf::Sound();
            sound->setBuffer(*buffer);
            sound->play();

            object->setState(ds::MenuState::Clicked);
            func();
            selected = object;
        } else {
            object->setState(ds::MenuState::Normal);
        }
    }
}

void ds::RelativeLayout::onMouseLeftReleased(MenuObject* object,
                                             sf::Event* event,
                                             std::function<void()> func) {
    if (event->mouseButton.button != sf::Mouse::Left) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Vector2i(x, y));

    object->setState(ds::MenuState::Normal);

    if (event->type == sf::Event::MouseButtonReleased && selected == object) {
        if (object->getRect().contains(mouse.x, mouse.y)) {
            func();
        }
    }
}

void ds::RelativeLayout::listenToElements(sf::Event* event) {
    for (MenuObject* element : elements) {
        onMouseLeftReleased(element, event, element->getActionReleased());
        onMouseMoved(element, event, element->getActionMoved());
        onMouseLeftPressed(element, event, element->getActionPressed());
    }
}
