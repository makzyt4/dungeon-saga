#include "../../include/Scene/TestScene.hpp"

void ds::TestScene::init() {

}

void ds::TestScene::update() {

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

    window->display();
}
