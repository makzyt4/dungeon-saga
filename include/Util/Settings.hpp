#ifndef DS_UTIL_SETTINGS_HPP
#define DS_UTIL_SETTINGS_HPP

#include <SFML/Graphics.hpp>

namespace ds {
    class Settings {
    private:
        sf::VideoMode videoMode;
        sf::String title;
        sf::Uint32 style;
    public:
        Settings();

        sf::VideoMode getVideoMode() const;
        sf::String getTitle() const;
        sf::Uint32 getStyle() const;
    };
}

#endif // DS_UTIL_SETTINGS_HPP
