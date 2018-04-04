#include "../../include/UI/Button.hpp"

void ds::Button::init() {
    text = "";
    selected = false;
}

sf::Vector2i ds::Button::getSize() const {
    return size;
}

std::string ds::Button::getText() const {
    return text;
}

void ds::Button::setSize(const sf::Vector2i& size) {
    this->size = sf::Vector2i(size.x, size.y);
    rect.width = size.x * 8;
    rect.height = size.y * 8;
}

void ds::Button::setText(const std::string& text) {
    this->text = text;
}

void ds::Button::draw() {
    sf::Texture* texture = loader->getTexture("menus.png");
    sf::IntRect spriteRect;

    int offset;

    if (state == MenuState::Highlighted) {
        offset = 1;
    } else if (state == MenuState::Clicked) {
        offset = 2;
    } else {
        offset = 0;
    }

    for (int j = 0; j < size.y; j++) {
        for (int i = 0; i < size.x; i++) {
            if (i == 0) {
                if (j == 0) {
                    spriteRect = sf::IntRect(0, offset * 24, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(0, 16 + offset * 24, 8, 8);
                } else {
                    spriteRect = sf::IntRect(0, 8 + offset * 24, 8, 8);
                }
            } else if (i == size.x - 1) {
                if (j == 0) {
                    spriteRect = sf::IntRect(16, offset * 24, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(16, 16 + offset * 24, 8, 8);
                } else {
                    spriteRect = sf::IntRect(16, 8 + offset * 24, 8, 8);
                }
            } else {
                if (j == 0) {
                    spriteRect = sf::IntRect(8, offset * 24, 8, 8);
                } else if (j == size.y - 1) {
                    spriteRect = sf::IntRect(8, 16 + offset * 24, 8, 8);
                } else {
                    spriteRect = sf::IntRect(8, 8 + offset * 24, 8, 8);
                }
            }

            sf::Sprite sprite;
            sprite.setTexture(*texture);

            sprite.setTextureRect(spriteRect);
            sprite.setPosition(rect.left + i * 8, rect.top + j * 8);
            window->draw(sprite);
        }
    }

    Text text;
    text.setWindow(window);
    text.setString(this->text);
    text.setPosition(sf::Vector2i(
                     rect.left + (rect.width - text.getSize().x) / 2,
                     rect.top + (rect.height - text.getSize().y) / 2));

    text.draw();
}

void ds::Button::onMouseHoverAction(sf::Event* event) {
    if (event->type != sf::Event::MouseMoved) {
        return;
    }

    int x = event->mouseMove.x;
    int y = event->mouseMove.y;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Vector2i(x, y));
    state = ds::MenuState::Normal;

    if (rect.contains(mouse.x, mouse.y)) {
        if (selected) {
            mouseHoverAction();
            state = ds::MenuState::Clicked;
        } else {
            state = ds::MenuState::Highlighted;
        }
    } else {
        state = ds::MenuState::Normal;
    }
}

void ds::Button::onMousePressedAction(sf::Event* event) {
    bool leftClicked = event->mouseButton.button == sf::Mouse::Left;

    if (event->type != sf::Event::MouseButtonPressed || !leftClicked) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Vector2i(x, y));
    selected = true;

    if (rect.contains(mouse.x, mouse.y)) {
        sf::SoundBuffer* buffer = loader->getSoundBuffer("click.ogg");
        sf::Sound* sound = new sf::Sound();
        sound->setBuffer(*buffer);
        sound->play();
        state = ds::MenuState::Clicked;
        mousePressedAction();
    } else {
        state = ds::MenuState::Highlighted;
    }
}

void ds::Button::onMouseReleasedAction(sf::Event* event) {
    bool leftClicked = event->mouseButton.button == sf::Mouse::Left;

    if (event->type != sf::Event::MouseButtonReleased || !leftClicked) {
        return;
    }

    int x = event->mouseButton.x;
    int y = event->mouseButton.y;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Vector2i(x, y));

    state = ds::MenuState::Normal;

    if (rect.contains(mouse.x, mouse.y)) {
        state = ds::MenuState::Highlighted;

        if (selected) {
            mouseReleasedAction();
        }
    }
    
    selected = false;
}
