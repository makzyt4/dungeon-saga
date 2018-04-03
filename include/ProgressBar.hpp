#ifndef DS_PROGRESS_BAR_HPP
#define DS_PROGRESS_BAR_HPP

#include <sstream>
#include "MenuObject.hpp"
#include "Text.hpp"

namespace ds {
    class ProgressBar : public MenuObject {
    private:
        int value;
        int minValue;
        int maxValue;
        int width;

    protected:
        virtual sf::Color barColor() = 0;

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

#endif // DS_PROGRESS_BAR_HPP
