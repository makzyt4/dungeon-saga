#include "../include/Screen.hpp"

ds::Screen::Screen(sf::RenderWindow* window, ResourceLoader* loader) {
    this->window = window;
    this->loader = loader;
}
