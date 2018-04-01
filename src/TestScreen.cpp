#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    generateView();
}

void ds::TestScreen::update() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }
}

void ds::TestScreen::draw() {
    window->clear();

    window->display();
}

void ds::TestScreen::control() {
    sf::sleep(sf::milliseconds(17));
}
