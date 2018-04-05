#include "../../include/Main/Main.hpp"

ds::Main::Main() {
    sf::VideoMode videoMode = settings.getVideoMode();
    sf::String title = settings.getTitle();
    sf::Uint32 style = settings.getStyle();

    sf::RenderWindow* window = new sf::RenderWindow(videoMode, title, style);
    ResourceLoader* loader = new ResourceLoader();
    Scene* scene = new ds::TestScene(window, loader);
    scene->init();

    ExitCode code = scene->getCode();

    do {
        scene->update();
        scene->control();
        scene->draw();
        code = scene->getCode();
    } while (code != ExitCode::Quit);
}

int main() {
    new ds::Main();
    return 0;
}
