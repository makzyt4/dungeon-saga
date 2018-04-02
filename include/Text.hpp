#ifndef DS_TEXT_HPP
#define DS_TEXT_HPP

#include <SFML/Graphics.hpp>
#include "DrawableObject.hpp"
#include "Font.hpp"

namespace ds {
    class Text : public DrawableObject {
    private:
        sf::Vector2i position;
        sf::Color color;
        std::string string;
        std::size_t fontSize;
        Font font;
        int width;
        int height;
        std::size_t currentWidth;

    public:
        Text();

        std::string getString() const;
        sf::Vector2i getPosition() const;
        std::size_t getFontSize() const;
        sf::Vector2i getSize() const;

        void setString(const std::string& string);
        void setPosition(const sf::Vector2i& position);
        void setFontSize(const std::size_t size);
        void setColor(const sf::Color& color);

        void draw(sf::RenderWindow* window);
    };
}

#endif // DS_TEXT_HPP
