#include "../../include/Scene/TestScene.hpp"

void ds::TestScene::init() {
    layout.setWindow(window);
    layout.setLoader(loader);

    player.setWindow(window);
    player.setLoader(loader);
    player.init();
    player.setPosition(sf::Vector2f(400, 300));

    button.init();
    button.setText("TEST");
    button.setSize(sf::Vector2i(5, 3));
    button.setPosition(sf::Vector2f(400, 300));
    button.setOnMouseReleasedAction([](){printf("TEST\n");});
    layout.addElement(&button);
}

void ds::TestScene::update() {
    player.update();
    generateView();
}

void ds::TestScene::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
        layout.listenToAll(&event);
        player.handleKeys(&event);
    }

    sf::sleep(sf::milliseconds(17));
}

void ds::TestScene::draw() {
    window->clear();
    player.draw();
    // layout.draw();
    window->display();
}
