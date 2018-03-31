#include "../include/TestScreen.hpp"

void ds::TestScreen::init() {
    button.setLoader(loader);
    button.init();
    button.setSize(sf::Vector2i(6, 3));
    button.setPosition(50, 50);
    button.setText("Test1");

    button2.setLoader(loader);
    button2.init();
    button2.setSize(sf::Vector2i(9, 3));
    button2.setPosition(50, 80);
    button2.setText("Test2");

    button3.setLoader(loader);
    button3.init();
    button3.setSize(sf::Vector2i(7, 3));
    button3.setPosition(50, 110);
    button3.setText("Test3");

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
    button2.draw(window);
    button3.draw(window);
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
        button2.setState(MenuState::Normal);
        button3.setState(MenuState::Normal);

        onMouseMove(&button, &event, [&]() -> void {
            button.setState(MenuState::Highlighted);
        });

        onMouseMove(&button2, &event, [&]() -> void {
            button2.setState(MenuState::Highlighted);
        });

        onMouseMove(&button3, &event, [&]() -> void {
            button3.setState(MenuState::Highlighted);
        });

        onClick(&button, &event, [&]() -> void {
            button.setState(MenuState::Clicked);
            std::cout << 1 << std::endl;
        });

        onClick(&button2, &event, [&]() -> void {
            button2.setState(MenuState::Clicked);
            std::cout << 2 << std::endl;
        });

        onClick(&button3, &event, [&]() -> void {
            button3.setState(MenuState::Clicked);
            std::cout << 3 << std::endl;
        });
    }
    animation.play();

    sf::sleep(sf::milliseconds(17));
}
