#include "../include/Screen.hpp"

ds::Screen::Screen(sf::RenderWindow* window, ResourceLoader* loader) {
    this->window = window;
    this->loader = loader;
    this->layout = new RelativeLayout(window, loader);
}

ds::ExitCode ds::Screen::getCode() {
    return code;
}

void ds::Screen::generateView() {
    int width = window->getSize().x;
    int height = window->getSize().y;
    sf::View view(sf::FloatRect(0, 0, width, height));
    view.zoom(0.5);
    window->setView(view);
}
