#ifndef DS_HEALTH_BAR_HPP
#define DS_HEALTH_BAR_HPP

#include "MenuObject.hpp"

namespace ds {
    class HealthBar : public MenuObject {
    private:
        int value;
        int minValue;
        int maxValue;
        int width;
    public:
        int getWidth() const;

        void setValue(const int& value);
        void setWidth(const int& width);

        void init();
        void setValues(const int& min, const int& max);
        void setPosition(int x, int y);
        void draw(sf::RenderWindow* window);
    };
}

#endif // DS_HEALTH_BAR_HPP
