#include "../../include/System/Timer.hpp"

ds::Timer::Timer() {
    running = true;
}

sf::Time ds::Timer::getElapsedTime() const {
    return elapsedTime;
}

bool ds::Timer::isRunning() const {
    return running;
}
void ds::Timer::update() {
    if (running) {
        elapsedTime += clock.getElapsedTime();
        clock.restart();
    }
}

void ds::Timer::stop() {
    clock.restart();
    elapsedTime = sf::Time();
    running = false;
}

void ds::Timer::restart() {
    clock.restart();
    elapsedTime = sf::Time();
    running = true;
}

void ds::Timer::unpause() {
    clock.restart();
    running = true;
}

void ds::Timer::pause() {
    running = false;
}
