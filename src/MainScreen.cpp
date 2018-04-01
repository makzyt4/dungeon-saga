#include "../include/MainScreen.hpp"

void ds::MainScreen::init() {
    startButton.setLoader(loader);
    startButton.init();
    startButton.setSize(sf::Vector2i(12, 4));
    startButton.setPosition(
        (window->getSize().x - startButton.getRect().width) / 2,
        (window->getSize().y - startButton.getRect().height) / 2 - 40);
    startButton.setText("New Game");

    optionsButton.setLoader(loader);
    optionsButton.init();
    optionsButton.setSize(sf::Vector2i(12, 4));
    optionsButton.setPosition(
        (window->getSize().x - optionsButton.getRect().width) / 2,
        (window->getSize().y - optionsButton.getRect().height) / 2);
    optionsButton.setText("Options");

    quitButton.setLoader(loader);
    quitButton.init();
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
        startButton.setState(MenuState::Normal);
        optionsButton.setState(MenuState::Normal);
        quitButton.setState(MenuState::Normal);

        onMouseMove(&startButton, &event, [&]() -> void {
            startButton.setState(MenuState::Highlighted);
        });

        onMouseMove(&optionsButton, &event, [&]() -> void {
            optionsButton.setState(MenuState::Highlighted);
        });

        onMouseMove(&quitButton, &event, [&]() -> void {
            quitButton.setState(MenuState::Highlighted);
        });

        onClick(&startButton, &event, [&]() -> void {
            startButton.setState(MenuState::Clicked);
        });

        onClick(&optionsButton, &event, [&]() -> void {
            optionsButton.setState(MenuState::Clicked);
        });

        onClick(&quitButton, &event, [&]() -> void {
            quitButton.setState(MenuState::Clicked);
        });
    }

    sf::sleep(sf::milliseconds(17));
}
