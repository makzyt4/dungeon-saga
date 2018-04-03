#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    sf::Vector2i offset(800, 800);

    generator.setLoader(loader);
    generator.setElements(&elements);
    generator.setLevelSize(5, 5);
    generator.setOffset(offset);

    text.setPosition(sf::Vector2i(400, 300));
    text.setString("TEST");

    hero.init(loader);
    hero.setPosition(offset.x * 16, offset.y * 16);
    printf("hero=%d,%d\n", offset.x * 16, offset.y * 16);

    healthBar.setLoader(loader);
    healthBar.init();

    magickaBar.setLoader(loader);
    magickaBar.init();

    staminaBar.setLoader(loader);
    staminaBar.init();

    generator.generateRoom();
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


    sf::Vector2i barPos = sf::Vector2i(center.x - window->getSize().x / 4 + 10,
                                       center.y - window->getSize().y / 4 + 10);
    healthBar.setPosition(barPos.x, barPos.y);
    magickaBar.setPosition(barPos.x, barPos.y + 12);
    staminaBar.setPosition(barPos.x, barPos.y + 24);

    generateView(hero.getCenter());
    hero.handleKeys();
    hero.update(&elements);
}

void ds::TestScreen::draw() {
    window->clear();

    drawBlocks();
    hero.draw(window);
    text.draw(window);
    healthBar.draw(window);
    magickaBar.draw(window);
    staminaBar.draw(window);

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
