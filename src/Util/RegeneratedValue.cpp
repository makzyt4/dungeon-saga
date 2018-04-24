#include "../../include/Util/RegeneratedValue.hpp"

ds::RegeneratedValue::RegeneratedValue()
    : RegeneratedValue(0, 0, 0) {}

ds::RegeneratedValue::RegeneratedValue(const int& min, const int& max,
                                       const int& value) {
    this->min = min;
    this->max = max;
    this->value = value;
    regeneration = 0;
}

void ds::RegeneratedValue::setMin(const int& value) {
    this->min = value;
}

void ds::RegeneratedValue::setMax(const int& value) {
    this->max = value;
}

void ds::RegeneratedValue::setValue(const int& value) {
    this->value = value;
}

void ds::RegeneratedValue::setRegeneration(const int& value) {
    this->regeneration = value;
}

void ds::RegeneratedValue::setRegenerationTime(const sf::Time& time) {
    this->regenerationTime = time;
}

void ds::RegeneratedValue::addValue(const int& value) {
    this->value += value;

    if (this->value > max) this->value = max;
    if (this->value < min) this->value = min;
}

void ds::RegeneratedValue::update() {
    if (clock.getElapsedTime() > regenerationTime) {
        addValue(regeneration);
        clock.restart();
    }
}

int ds::RegeneratedValue::getValue() const {
    return value;
}

float ds::RegeneratedValue::fillRatio() const {
    return (float)(value - min) / (float)(max - min);
}