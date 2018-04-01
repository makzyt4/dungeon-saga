#include "../include/MainScreen.hpp"

void ds::MainScreen::init() {
    layout->addElement(&startButton);
    layout->addElement(&optionsButton);
    layout->addElement(&quitButton);

    quitButton.setActionReleased([this](){
        code = ds::ExitCode::Quit;
        window->close();
    });

    startButton.setSize(sf::Vector2i(12, 4));
    startButton.setPosition(
        (window->getSize().x - startButton.getRect().width) / 2,
        (window->getSize().y - startButton.getRect().height) / 2 - 40);
    startButton.setText("New Game");

    optionsButton.setSize(sf::Vector2i(12, 4));
    optionsButton.setPosition(
        (window->getSize().x - optionsButton.getRect().width) / 2,
        (window->getSize().y - optionsButton.getRect().height) / 2);
    optionsButton.setText("Options");

    quitButton.setSize(sf::Vector2i(12, 4));
    quitButton.setPosition(
        (window->getSize().x - quitButton.getRect().width) / 2,
        (window->getSize().y - quitButton.getRect().height) / 2 + 40);
    quitButton.setText("Quit");

    generateView();
}

void ds::MainScreen::update() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        } else if (event.type == sf::Event::Resized) {
            generateView();
        }

        layout->listenToElements(&event);
    }
}

void ds::MainScreen::draw() {
    window->clear();

    startButton.draw(window);
    optionsButton.draw(window);
    quitButton.draw(window);

    window->display();
}

void ds::MainScreen::control() {
    sf::sleep(sf::milliseconds(17));
}
