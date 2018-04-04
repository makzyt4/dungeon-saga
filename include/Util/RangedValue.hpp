#ifndef DS_UTIL_RANGED_VALUE_HPP
#define DS_UTIL_RANGED_VALUE_HPP

#include <algorithm>

namespace ds {
    class RangedValue {
    private:
        int minValue;
        int maxValue;
        int value;
    public:
        RangedValue(const int& min, const int& max, const int& value);

        int getMinValue() const;
        int getMaxValue() const;
        int getValue() const;

        void addToValue(const int& addition);
    };
}

#endif // DS_UTIL_RANGED_VALUE_HPP
