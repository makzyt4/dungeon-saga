#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Animation.hpp"
#include "../include/Timer.hpp"
#include "../include/TextureLoader.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ds::Timer timer;

    ds::TextureLoader loader;
    sf::Texture* texture = loader.getTexture("../res/hero.png");

    ds::Animation animation(sf::seconds(0.5));
    animation.setSpriteSheet(texture);
    animation.addFrame(sf::IntRect(0, 0, 32, 32));
    animation.addFrame(sf::IntRect(32, 0, 32, 32));

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
        animation.play();
        timer.update();

        window.clear();
        window.draw(shape);
        window.draw(animation.currentSprite());
        window.display();
        sf::sleep(sf::milliseconds(17));
    }

    return 0;
}
