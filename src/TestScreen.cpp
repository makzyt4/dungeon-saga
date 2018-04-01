#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    hero.init(loader);
    hero.setPosition(400, 300);

    generateView();
}

void ds::TestScreen::update() {
}

void ds::TestScreen::draw() {
    window->clear();

    hero.draw(window);

    window->display();
}

void ds::TestScreen::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }

    hero.update();

    sf::sleep(sf::milliseconds(17));
}
