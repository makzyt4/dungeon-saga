#ifndef DS_UI_EXPERIENCEBAR_HPP
#define DS_UI_EXPERIENCEBAR_HPP

#include "../Graphics/DrawableObject.hpp"
#include "../Util/RegeneratedValue.hpp"
#include "../Graphics/Text.hpp"

namespace ds {
    class ExperienceBar : public DrawableObject {
    private:
        RegeneratedValue* value;
    public:
        void setValue(RegeneratedValue* value);

        void draw();
    };
}

#endif // DS_UI_EXPERIENCEBAR_HPP