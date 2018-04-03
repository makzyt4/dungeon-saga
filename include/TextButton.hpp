#ifndef DS_TEXT_BUTTON_HPP
#define DS_TEXT_BUTTON_HPP

#include "MenuObject.hpp"
#include "Text.hpp"

namespace ds {
    class TextButton : public MenuObject {
    private:
        sf::Font* font;
        std::string text;
        sf::Vector2i size;
    public:
        using MenuObject::MenuObject;

        std::string getText();
        sf::Vector2i getSize();

        void setText(std::string text);
        void setSize(sf::Vector2i size);

        void init();
        void setPosition(int x, int y);
        void draw(sf::RenderWindow* window);
    };
}

#endif
