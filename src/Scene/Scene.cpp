#include "../../include/Scene/Scene.hpp"

ds::Scene::Scene(sf::RenderWindow* window, ds::ResourceLoader* loader) {
    this->window = window;
    this->loader = loader;
    code = ds::ExitCode::Running;
}

ds::ExitCode ds::Scene::getCode() const {
    return code;
}

void ds::Scene::generateView() {
    int width = window->getSize().x;
    int height = window->getSize().y;
    sf::View view(sf::FloatRect(0, 0, width, height));
    view.zoom(0.5);
    window->setView(view);
}

void ds::Scene::generateView(sf::Vector2i center) {
    int width = window->getSize().x;
    int height = window->getSize().y;
    sf::View view(sf::FloatRect(0, 0, width, height));
    view.setCenter(center.x, center.y);
    view.zoom(0.5);
    window->setView(view);
}
