#ifndef DS_TEXT_HPP
#define DS_TEXT_HPP

#include <SFML/Graphics.hpp>
#include "DrawableObject.hpp"
#include "Font.hpp"

namespace ds {
    class Text : public DrawableObject {
    private:
        sf::IntRect position;
        sf::Color color;
        std::string string;
        std::size_t size;
        Font font;

    public:
        std::string getString() const;
        sf::IntRect getPosition() const;
        std::size_t getSize() const;

        void setString(const std::string& string);
        void setPosition(const sf::IntRect& position);
        void setSize(const std::size_t size);

        void draw(sf::RenderWindow* window);
    };
}

#endif // DS_TEXT_HPP
