#include "../../include/Game/Bomb.hpp"

void ds::Bomb::init() {
    exploding = false;
    explosionEnded = false;
    exploded = false;

    sf::Texture* explosionTexture = loader->getTexture("explosion.png");
    
    explosion = Animation(sf::seconds(0.02), false);
    explosion.setSpriteSheet(explosionTexture);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            explosion.addFrame(sf::IntRect(j * 64, i * 64, 64, 64));
        }
    }
}

void ds::Bomb::draw() {
    if (!exploding) {
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
        sprite.setPosition(rect.left + 8, rect.top + 8);
        window->draw(sprite);
    } else {
        sf::Sprite explosionSprite;
        explosionSprite = explosion.currentSprite();
        explosionSprite.setPosition(rect.left - 16, rect.top - 16);

        window->draw(explosionSprite);
        explosion.play();

        if (explosion.isPaused()) {
            explosionEnded = true;
        }
    }
}

void ds::Bomb::update() {
    if (bombClock.getElapsedTime() > sf::seconds(5)) {
        exploding = true;
    }
}