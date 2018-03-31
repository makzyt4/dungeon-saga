#include "../include/Screen.hpp"

ds::Screen::Screen(const sf::RenderWindow& window) {
    this->window = &window;
}

void ds::Screen::run() {
    update();
    control();
    draw();
}
