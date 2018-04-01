#include "../include/Screen.hpp"

ds::Screen::Screen(sf::RenderWindow* window, ResourceLoader* loader) {
    this->window = window;
    this->loader = loader;
    this->layout = new RelativeLayout(loader);
}

ds::ExitCode ds::Screen::getCode() {
    return code;
}
