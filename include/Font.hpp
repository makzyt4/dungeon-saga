#ifndef DS_FONT_HPP
#define DS_FONT_HPP

#include <map>
#include <array>
#include <SFML/Graphics.hpp>
#include "ResourceLoader.hpp"

namespace ds {
    class Font {
    private:
        std::map<char, std::uint64_t> charMap;

    public:
        Font();

        std::uint64_t getChar(char c);
        void drawCharacter(sf::RenderWindow* window, char c,
                           sf::Vector2i position, std::size_t size,
                           sf::Color color);
    };
}

#endif
