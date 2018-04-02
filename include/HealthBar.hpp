#ifndef DS_HEALTH_BAR_HPP
#define DS_HEALTH_BAR_HPP

#include "MenuObject.hpp"

namespace ds {
    class HealthBar : public MenuObject {
    public:
        void init();
        void setPosition(int x, int y);
        void draw(sf::RenderWindow* window);
    };
}

#endif // DS_HEALTH_BAR_HPP
