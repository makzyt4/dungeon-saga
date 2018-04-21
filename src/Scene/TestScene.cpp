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
    sf::sleep(sf::milliseconds(17));
}

void ds::TestScene::draw() {
    window->clear();
    // layout.draw();
    level.draw();
    window->display();
}
