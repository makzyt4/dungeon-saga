#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    text.setPosition(sf::Vector2i(400, 300));
    text.setString("TEST");

    hero.init(loader);
    hero.setPosition(400, 300);

    for (int i = 0; i < 10; i++) {
        Block* brick = new BrickBlock();
        brick->setLoader(loader);
        brick->init();
        elements.addBlock(brick, 20 + i, 24);
    }
}

void ds::TestScreen::update() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }

    generateView(hero.getCenter());
    hero.handleKeys();
    hero.update(&elements);
}

void ds::TestScreen::draw() {
    window->clear();

    elements.drawAll(window);
    hero.draw(window);
    text.draw(window);

    window->display();
}

void ds::TestScreen::control() {
    sf::sleep(sf::milliseconds(17));
}
