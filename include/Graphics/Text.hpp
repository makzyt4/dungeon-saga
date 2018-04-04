#ifndef DS_GRAPHICS_TEXT_HPP
#define DS_GRAPHICS_TEXT_HPP

#include "DrawableObject.hpp"
#include "Font.hpp"

namespace ds {
    class Text : public DrawableObject {
    private:
        std::string string;
        sf::Color color;
        std::uint8_t fontSize;
        Font font;
    public:
        Text();

        std::string getString() const;
        sf::Vector2i getPosition() const;
        std::size_t getFontSize() const;
        sf::Vector2i getSize() const;

        void setString(const std::string& string);
        void setPosition(const sf::Vector2i& position);
        void setFontSize(const std::uint8_t& size);
        void setColor(const sf::Color& color);

        void draw(sf::RenderWindow* window);
    };
}

#endif // DS_GRAPHICS_TEXT_HPP
