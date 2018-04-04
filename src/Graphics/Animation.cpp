#include "../../include/Graphics/Animation.hpp"

ds::Animation::Animation()
    : Animation(sf::seconds(0.2)) {}

ds::Animation::Animation(const sf::Time& frameTime)
    : Animation(frameTime, true) {}

ds::Animation::Animation(const sf::Time& frameTime, const bool& looped)
    : Animation(frameTime, looped, false) {}

ds::Animation::Animation(const sf::Time& frameTime, const bool& looped,
                         const bool& paused) {
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

void ds::Animation::setFrameTime(const sf::Time& frameTime) {
    this->frameTime = frameTime;
}

void ds::Animation::addFrame(const sf::IntRect& frame) {
    frames.push_back(frame);
}

void ds::Animation::play() {
    if (!timer.isRunning()) {
        return;
    }

    timer.update();

    if (timer.getElapsedTime() >= frameTime) {
        frameIndex++;
        timer.restart();

        if (frameIndex >= frames.size()) {
            frameIndex = looped ? 0 : frames.size() - 1;

            if (!looped) {
                paused = true;
            }
        }
    }
}

void ds::Animation::restart() {
    timer.restart();
    frameIndex = 0;
}

void ds::Animation::pause() {
    timer.pause();
}

void ds::Animation::unpause() {
    timer.unpause();
}

sf::Sprite ds::Animation::currentSprite() {
    sf::Sprite sprite;
    sprite.setTexture(*spriteSheet);
    sprite.setTextureRect(frames[frameIndex]);
    return sprite;
}
