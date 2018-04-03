#ifndef DS_GRAPHICS_FONT_HPP
#define DS_GRAPHICS_FONT_HPP

#include <map>
#include <SFML/Graphics.hpp>

namespace ds {
    class Font {
    private:
        std::map<char, std::uint64_t> charMap;
    public:
        Font();

        std::uint64_t getCharacter(char c);
        void drawCharacter(sf::RenderWindow* window, char c,
                           const sf::Vector2i& position,
                           const std::uint8_t& size, const sf::Color& color);
    };
}

#endif // DS_GRAPHICS_FONT_HPP
