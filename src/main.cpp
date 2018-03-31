#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Timer.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ds::Timer timer;

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

        std::cout << timer.getElapsedTime().asSeconds() << std::endl;

        window.clear();
        window.draw(shape);
        window.display();
        sf::sleep(sf::milliseconds(17));
    }

    return 0;
}
