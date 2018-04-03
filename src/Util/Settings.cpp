#include "../../include/Util/Settings.hpp"

ds::Settings::Settings() {
    videoMode = sf::VideoMode(800, 600);
    title = "Dungeon Saga";
    style = sf::Style::Resize | sf::Style::Close;
}

sf::VideoMode ds::Settings::getVideoMode() const {
    return videoMode;
}

sf::String ds::Settings::getTitle() const {
    return title;
}

sf::Uint32 ds::Settings::getStyle() const {
    return style;
}
