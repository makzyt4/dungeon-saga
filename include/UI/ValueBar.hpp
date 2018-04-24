#ifndef DS_UI_VALUEBAR_HPP
#define DS_UI_VALUEBAR_HPP

#include "../Graphics/DrawableObject.hpp"
#include "../Util/RegeneratedValue.hpp"

namespace ds {
    class ValueBar : public DrawableObject {
    private:
        sf::Color color;
        RegeneratedValue* value;
    public:
        void setColor(const sf::Color& color);
        void setValue(RegeneratedValue* value);

        void draw();
    };
}

#endif // DS_UI_VALUEBAR_HPP