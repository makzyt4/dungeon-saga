#include "../../include/Util/RangedValue.hpp"

ds::RangedValue::RangedValue(const int& min, const int& max,
                         const int& value) {
    this->value = value;
    minValue = min;
    maxValue = max;
}

int ds::RangedValue::getMinValue() const {
    return this->minValue;
}

int ds::RangedValue::getMaxValue() const {
    return this->maxValue;
}

int ds::RangedValue::getValue() const {
    return this->value;
}

void ds::RangedValue::addToValue(const int& addition) {
    value += addition;
    value = std::min(value, maxValue);
    value = std::max(value, minValue);
}
