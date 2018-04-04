#include "../../include/Scene/MainScene.hpp"

void ds::MainScene::init() {

}

void ds::MainScene::update() {

}

void ds::MainScene::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }
    }

    sf::sleep(sf::milliseconds(17));
}

void ds::MainScene::draw() {
    window->clear();

    window->display();
}
