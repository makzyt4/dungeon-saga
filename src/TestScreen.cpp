#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    button.setLoader(loader);
    button.init();
    button.setSize(sf::Vector2i(5, 3));
    button.setPosition(50, 50);

    shape = sf::CircleShape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture* texture = loader->getTexture("hero.png");

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
        }
        button.setState(MenuState::Normal);

        onMouseMove(&button, &event, [&]() -> void {
            button.setState(MenuState::Highlighted);
        });

        onClick(&button, &event, [&]() -> void {
            button.setState(MenuState::Clicked);
        });
    }
    animation.play();

    sf::sleep(sf::milliseconds(17));
}
