#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    text.setPosition(sf::Vector2i(400, 300));
    text.setString("TEST");

    hero.init(loader);
    hero.setPosition(400, 300);

    Block* brick = new BrickBlock();
    brick->setLoader(loader);
    brick->init();
    brick->setPosition(432, 320);

    Block* brick2 = new BrickBlock();
    brick2->setLoader(loader);
    brick2->init();
    brick2->setPosition(432, 336);

    for (int i = 0; i < 7; i++) {
        Block* brick = new BrickBlock();
        brick->setLoader(loader);
        brick->init();
        brick->setPosition(320 + i * 16, 352);

        elements.addBlock(brick);
    }

    for (int i = 0; i < 10; i++) {
        Block* brick = new BrickBlockBackground();
        brick->setLoader(loader);
        brick->init();
        brick->setPosition(320 + i * 16, 304);

        elements.addBlock(brick);
    }


    elements.addBlock(brick);
    elements.addBlock(brick2);
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
