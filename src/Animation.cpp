#include "../include/Animation.hpp"

ds::Animation::Animation()
    : Animation(sf::seconds(0.2)) {}

ds::Animation::Animation(sf::Time frameTime)
    : Animation(frameTime, true) {}

ds::Animation::Animation(sf::Time frameTime, bool looped)
    : Animation(frameTime, looped, false) {}

ds::Animation::Animation(sf::Time frameTime, bool looped, bool paused) {
    this->frameTime = frameTime;
    this->looped = looped;
    this->paused = paused;

    spriteSheet = NULL;
    frameIndex = 0;
}

bool ds::Animation::isPaused() const {
    return paused;
}

bool ds::Animation::isLooped() const {
    return looped;
}

sf::Time ds::Animation::getFrameTime() const {
    return frameTime;
}

void ds::Animation::setSpriteSheet(sf::Texture* spriteSheet) {
    this->spriteSheet = spriteSheet;
}

void ds::Animation::setFrameTime(sf::Time frameTime) {
    this->frameTime = frameTime;
}

void ds::Animation::addFrame(sf::IntRect frame) {
    frames.push_back(frame);
}

void ds::Animation::play() {
    if (paused) {
        return;
    }

    timer.update();

    if (timer.getElapsedTime() >= frameTime) {
        frameIndex++;
        timer.restart();

        if (frameIndex >= frames.size()) {
            frameIndex = looped ? 0 : frames.size();

            if (!looped) {
                paused = true;
            }
        }
    }
}

void ds::Animation::restart() {
    timer.restart();
}

void ds::Animation::pause() {
    paused = true;
}

void ds::Animation::unpause() {
    paused = false;
}

sf::Sprite ds::Animation::currentSprite() {
    sf::Sprite sprite;

    sprite.setTexture(*spriteSheet);
    sprite.setTextureRect(frames[frameIndex]);

    return sprite;
}
