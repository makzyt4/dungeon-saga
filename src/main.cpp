#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/TestScreen.hpp"

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(200, 200),
                                                                 "SFML works!");
    ds::ResourceLoader* loader = new ds::ResourceLoader();

    ds::Screen* screen = new ds::TestScreen(window, loader);
    screen->init();

    while (window->isOpen()) {
        screen->update();
        screen->draw();
        screen->control();
    }

    return 0;
}
