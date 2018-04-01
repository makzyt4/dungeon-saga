#include "../include/MainScreen.hpp"

void ds::MainScreen::init() {
    layout->addElement(&startButton);
    layout->addElement(&optionsButton);
    layout->addElement(&quitButton);

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
}

void ds::MainScreen::update() {
}

void ds::MainScreen::draw() {
    window->clear();

    startButton.draw(window);
    optionsButton.draw(window);
    quitButton.draw(window);

    window->display();
}

void ds::MainScreen::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        }

        layout->onMouseLeftReleased(&startButton, &event, [](){});
        layout->onMouseLeftReleased(&optionsButton, &event, [](){});
        layout->onMouseLeftReleased(&quitButton, &event, [](){});

        layout->onMouseMove(&startButton, &event, [](){});
        layout->onMouseMove(&optionsButton, &event, [](){});
        layout->onMouseMove(&quitButton, &event, [](){});

        layout->onMouseLeftPressed(&startButton, &event, [](){});
        layout->onMouseLeftPressed(&optionsButton, &event, [](){});
        layout->onMouseLeftPressed(&quitButton, &event, [](){});
    }

    sf::sleep(sf::milliseconds(17));
}
