#ifndef DS_TEXT_BUTTON_HPP
#define DS_TEXT_BUTTON_HPP

#include "MenuObject.hpp"

namespace ds {
    class TextButton : public MenuObject {
    private:
        std::string text;
    public:
        using MenuObject::MenuObject;
    };
}

#endif
