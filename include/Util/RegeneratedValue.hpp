#ifndef DS_UTIL_REGENERATED_VALUE_HPP
#define DS_UTIL_REGENERATED_VALUE_HPP

#include <cmath>
#include <SFML/System.hpp>
#include "../Interface/Updatable.hpp"

namespace ds {
    class RegeneratedValue : public Updatable {
    private:
        int min;
        int max;
        int value;
        int regeneration;
        sf::Clock clock;
        sf::Time regenerationTime;
    public:
        RegeneratedValue();
        RegeneratedValue(const int& min, const int& max, const int& value);

        int getValue() const;

        void setMin(const int& value);
        void setMax(const int& value);
        void setValue(const int& value);
        void setRegeneration(const int& value);
        void setRegenerationTime(const sf::Time& time);

        void addValue(const int& value);
        void update();
        float fillRatio() const;
    };
}

#endif // DS_UTIL_REGENERATED_VALUE_HPP
