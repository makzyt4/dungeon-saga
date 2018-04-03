#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/TestScreen.hpp"
#include "../include/MainScreen.hpp"
#include "../include/ExitCode.hpp"

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600),
                                "Dungeon Saga");
    ds::ResourceLoader* loader = new ds::ResourceLoader();

    ds::Screen* screen = new ds::MainScreen(window, loader);
    screen->init();

    ds::ExitCode code = ds::ExitCode::Running;

    while (code != ds::ExitCode::Quit) {
        screen->update();
        screen->draw();
        screen->control();
        code = screen->getCode();

        if (code == ds::ExitCode::Test) {
            screen = new ds::TestScreen(window, loader);
            screen->init();
        }
    }

    return 0;
}
