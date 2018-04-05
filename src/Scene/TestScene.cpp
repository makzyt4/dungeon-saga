#include "../../include/Scene/TestScene.hpp"

void ds::TestScene::init() {
    layout.setWindow(window);
    layout.setLoader(loader);

    level.setWindow(window);
    level.setLoader(loader);

    player.setWindow(window);
    player.setLoader(loader);
    player.init();
    player.setPosition(sf::Vector2f(400, 368));

    button.init();
    button.setText("TEST");
    button.setSize(sf::Vector2i(5, 3));
    button.setPosition(sf::Vector2f(400, 300));
    button.setOnMouseReleasedAction([](){printf("TEST\n");});
    layout.addElement(&button);

    for (int i = 0; i < 10; i++) {
        level.addBlock(new BlockBrick(), 20 + i, 21);
    }

    level.addBlock(new BlockBrick(), 20, 22);
    level.addBlock(new BlockBrick(), 20, 23);
    level.addBlock(new BlockBrick(), 20, 24);
    level.addBlock(new BlockBrick(), 29, 22);
    level.addBlock(new BlockBrick(), 29, 23);
    level.addBlock(new BlockBrick(), 29, 24);

    for (int i = 0; i < 10; i++) {
        level.addBlock(new BlockBrick(), 20 + i, 25);
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 8; i++) {
            level.addBlock(new BlockBackground(), 21 + i, 22 + j);
        }
    }

    level.setPlayer(&player);
}

void ds::TestScene::update() {
    level.update();
    generateView();
}

void ds::TestScene::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
        // layout.listenToAll(&event);
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
