#include "../../include/Scene/TestScene.hpp"

void ds::TestScene::init() {
    layout.setWindow(window);
    layout.setLoader(loader);

    panel.init();
    panel.setSize(sf::Vector2i(5, 3));
    panel.setPosition(sf::Vector2i(400, 300));
    layout.addElement(&panel);
}

void ds::TestScene::update() {
    generateView();
}

void ds::TestScene::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }

    sf::sleep(sf::milliseconds(17));
}

void ds::TestScene::draw() {
    window->clear();
    layout.draw();
    window->display();
}
