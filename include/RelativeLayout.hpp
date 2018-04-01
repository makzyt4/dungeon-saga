#ifndef DS_RELATIVE_LAYOUT_HPP
#define DS_RELATIVE_LAYOUT_HPP

#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>
#include "MenuObject.hpp"
#include "ResourceLoader.hpp"

namespace ds {
    class RelativeLayout {
    private:
        ResourceLoader* loader;
        std::vector<MenuObject*> elements;
        MenuObject* selected;

    public:
        RelativeLayout(ResourceLoader* loader);

        void addElement(MenuObject* element);
        void onMouseMove(MenuObject* object, sf::Event* event,
                         std::function<void()> function);
        void onMouseLeftPressed(MenuObject* object, sf::Event* event,
                                std::function<void()> function);
        void onMouseLeftReleased(MenuObject* object, sf::Event* event,
                                 std::function<void()> function);
        void listenToElements(sf::Event* event);
    };
}

#endif // DS_RELATIVE_LAYOUT_HPP
