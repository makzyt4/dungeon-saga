#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Timer.hpp"
#include "../include/TextureLoader.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ds::Timer timer;

    ds::TextureLoader loader;
    sf::Texture* texture = loader.getTexture("../res/hero.png");
    sf::Texture* texture2 = loader.getTexture("../res/hero.png");
    sf::Texture* texture3 = loader.getTexture("../res/hero1.png");
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    sf::Sprite sprite2;
    sprite.setTexture(*texture2);

    sf::Sprite sprite3;
    sprite.setTexture(*texture3);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    if (timer.isRunning()) {
                        timer.pause();
                    } else {
                        timer.unpause();
                    }
                }
            }
        }

        timer.update();

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
        sf::sleep(sf::milliseconds(17));
    }

    return 0;
}
