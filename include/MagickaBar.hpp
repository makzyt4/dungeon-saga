#ifndef DS_MAGICKA_BAR_HPP
#define DS_MAGICKA_BAR_HPP

#include "ProgressBar.hpp"

namespace ds {
    class MagickaBar : public ProgressBar {
    protected:
        sf::Color barColor();
    };
}

#endif // DS_MAGICKA_BAR_HPP
