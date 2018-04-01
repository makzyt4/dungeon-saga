#ifndef DS_FONT_LOADER_HPP
#define DS_FONT_LOADER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

namespace ds {
    class FontLoader {
    private:
        std::map<std::string, sf::Font*> fontMap;
    public:
        FontLoader();
        sf::Font* getFont(std::string path);
    };
}

#endif // DS_FONT_LOADER_HPP
