#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    text.setPosition(sf::Vector2i(400, 300));
    text.setString("TEST");

    hero.init(loader);
    hero.setPosition(400, 300);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Block* brick = new BrickBlockBackground();
            brick->setLoader(loader);
            brick->init();
            elements.addBlock(brick, 20 + i, 15 + j);
        }
    }

    for (int i = 0; i < 10; i++) {
        Block* brick = new BrickBlock();
        brick->setLoader(loader);
        brick->init();
        elements.addBlock(brick, 20 + i, 24);
    }

    Block* door = new BrickDoorBackground();
    door->setLoader(loader);
    door->init();
    elements.addBlock(door, 22, 22);
}

void ds::TestScreen::update() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }

    sf::Vector2i center = hero.getCenter();


    sf::Vector2i textPos = sf::Vector2i(center.x - window->getSize().x / 4,
                                        center.y - window->getSize().y / 4);
    text.setPosition(textPos);
    printf("%d, %d\n", textPos.x, textPos.y);

    generateView(hero.getCenter());
    hero.handleKeys();
    hero.update(&elements);
}

void ds::TestScreen::draw() {
    window->clear();

    drawBlocks();
    hero.draw(window);
    text.draw(window);

    window->display();
}

void ds::TestScreen::control() {
    sf::sleep(sf::milliseconds(17));
}

void ds::TestScreen::drawBlocks() {
    for (Block* block : elements.getBlocks()) {
        sf::Vector2i center = hero.getCenter();
        float distance =
            std::sqrt(std::pow(center.x - block->getRect().left, 2) +
                      std::pow(center.y - block->getRect().top, 2)) * 3;
        if (distance <= std::max(window->getSize().x, window->getSize().y)) {
            block->draw(window);
        }
    }
}
