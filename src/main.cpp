#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/MainScreen.hpp"
#include "../include/ExitCode.hpp"

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600),
                                "Dungeon Saga",
                                sf::Style::None | sf::Style::Close);
    ds::ResourceLoader* loader = new ds::ResourceLoader();

    ds::Screen* screen = new ds::MainScreen(window, loader);
    screen->init();

    ds::ExitCode code = ds::ExitCode::Running;

    while (code != ds::ExitCode::Quit) {
        screen->update();
        screen->draw();
        screen->control();
        code = screen->getCode();
    }

    return 0;
}
