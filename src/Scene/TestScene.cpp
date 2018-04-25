#include "../../include/Scene/TestScene.hpp"

void ds::TestScene::init() {
    layout.setWindow(window);
    layout.setLoader(loader);

    level.setWindow(window);
    level.setLoader(loader);

    player.setWindow(window);
    player.setLoader(loader);
    player.init();
    player.setPosition(sf::Vector2f(1296, 1256));
    level.setPlayer(&player);

    button.init();
    button.setText("TEST");
    button.setSize(sf::Vector2i(5, 3));
    button.setPosition(sf::Vector2f(448, 300));
    button.setOnMouseReleasedAction([](){printf("TEST\n");});
    layout.addElement(&button);

    healthBar.setWindow(window);
    healthBar.setLoader(loader);
    healthBar.setColor(sf::Color::Red);
    healthBar.setValue(&player.health);

    staminaBar.setWindow(window);
    staminaBar.setLoader(loader);
    staminaBar.setColor(sf::Color::Green);
    staminaBar.setValue(&player.stamina);

    magickaBar.setWindow(window);
    magickaBar.setLoader(loader);
    magickaBar.setColor(sf::Color::Blue);
    magickaBar.setValue(&player.magicka);

    expBar.setWindow(window);
    expBar.setLoader(loader);
    expBar.setValue(&player.experience);

    bombText.setWindow(window);
    bombText.setLoader(loader);
    bombText.setColor(sf::Color::White);

    level.generateLevel(10);
}

void ds::TestScene::update() {
    if (clock.getElapsedTime().asSeconds() >= 1) {
        printf("FPS: %d\n", tick);
        tick = 0;
        clock.restart();
    }

    level.update();
    generateView(player.getCenter());

    sf::Vector2f fixedPosition(player.getCenter().x - window->getSize().x / 4, 
                               player.getCenter().y - window->getSize().y / 4);

    sf::Vector2f fixedEndPosition(player.getCenter().x + window->getSize().x / 4, 
                                  player.getCenter().y + window->getSize().y / 4);

    healthBar.setPosition(sf::Vector2f(fixedPosition.x + 10, fixedPosition.y + 5));
    staminaBar.setPosition(sf::Vector2f(fixedPosition.x + 10, fixedPosition.y + 20));
    magickaBar.setPosition(sf::Vector2f(fixedPosition.x + 10, fixedPosition.y + 35));
    expBar.setPosition(sf::Vector2f(fixedPosition.x + 10, fixedPosition.y + 50));

    bombText.setString("[B] Bombs: " + std::to_string(player.bombs));
    bombText.setPosition(sf::Vector2f(fixedEndPosition.x - 120, fixedEndPosition.y - 10));

    tick++;
}

void ds::TestScene::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }

    player.handleKeys();
    //sf::sleep(sf::milliseconds(10));
}

void ds::TestScene::draw() {
    window->clear();
    // layout.draw();
    level.draw();

    // Draw UI
    healthBar.draw();
    staminaBar.draw();
    magickaBar.draw();
    expBar.draw();

    bombText.draw();

    window->display();
}
