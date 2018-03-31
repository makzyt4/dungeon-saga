#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    button.setLoader(loader);
    button.init();
    button.setSize(sf::Vector2i(5, 3));
    button.setPosition(0, 0);

    shape = sf::CircleShape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture* texture = loader->getTexture("../res/hero.png");

    animation = ds::Animation(sf::seconds(0.5));
    animation.setSpriteSheet(texture);
    animation.addFrame(sf::IntRect(0, 0, 32, 32));
    animation.addFrame(sf::IntRect(32, 0, 32, 32));
}

void ds::TestScreen::update() {
    animation.play();
}

void ds::TestScreen::draw() {
    window->clear();
    window->draw(shape);
    button.draw(window);
    window->draw(animation.currentSprite());
    window->display();
}

void ds::TestScreen::control() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            code = ds::ExitCode::Quit;
            window->close();
        } else if (event.type == sf::Event::MouseButtonPressed
                   && event.mouseButton.button == sf::Mouse::Left) {
            if (button.getRect().contains(event.mouseButton.x,
                                          event.mouseButton.y)) {
                button.setState(MenuState::Clicked);
            }
        } else if (event.type == sf::Event::MouseMoved) {
            if (button.getRect().contains(event.mouseMove.x,
                                          event.mouseMove.y)) {
                button.setState(MenuState::Highlighted);
            } else {
                button.setState(MenuState::Normal);
            }
        } else if (event.type == sf::Event::MouseButtonReleased) {
            button.setState(MenuState::Normal);
        }
    }
    animation.play();

    sf::sleep(sf::milliseconds(17));
}
