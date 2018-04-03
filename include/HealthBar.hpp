#ifndef DS_HEALTH_BAR_HPP
#define DS_HEALTH_BAR_HPP

#include "ProgressBar.hpp"

namespace ds {
    class HealthBar : public ProgressBar {
    protected:
        sf::Color barColor();
    };
}

#endif // DS_HEALTH_BAR_HPP
