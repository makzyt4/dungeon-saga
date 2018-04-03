#ifndef DS_STAMINA_BAR_HPP
#define DS_STAMINA_BAR_HPP

#include "ProgressBar.hpp"

namespace ds {
    class StaminaBar : public ProgressBar {
    protected:
        sf::Color barColor();
    };
}

#endif // DS_STAMINA_BAR_HPP
