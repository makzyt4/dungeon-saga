#include "../../include/Game/Bomb.hpp"

void ds::Bomb::init() {
    exploded = false;
}

void ds::Bomb::draw() {
    if (!exploded) {
        ds::Text clockText;
        clockText.setWindow(window);
        clockText.setLoader(loader);
        clockText.setColor(sf::Color::White);
        clockText.setString(std::to_string(5 - (int) bombClock.getElapsedTime().asSeconds()));
        clockText.setPosition(sf::Vector2f(rect.left + 8, rect.top - 8));
        clockText.draw();

        sf::Texture* texture = loader->getTexture("objects.png");
        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.setPosition(rect.left, rect.top);
        window->draw(sprite);
    }
}

void ds::Bomb::update() {
    if (bombClock.getElapsedTime() > sf::seconds(5)) {
        exploded = true;
    }
}