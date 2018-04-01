#ifndef DS_ANIMATION_HPP
#define DS_ANIMATION_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Timer.hpp"

namespace ds {
    class Animation {
    private:
        bool paused;
        bool looped;
        std::size_t frameIndex;

        sf::Time frameTime;
        ds::Timer timer;
        sf::Texture* spriteSheet;
        std::vector<sf::IntRect> frames;

    public:
        Animation();
        Animation(sf::Time frameTime);
        Animation(sf::Time frameTime, bool looped);
        Animation(sf::Time frameTime, bool looped, bool paused);

        bool isPaused() const;
        bool isLooped() const;
        sf::Time getFrameTime() const;

        void setSpriteSheet(sf::Texture* spriteSheet);
        void setFrameTime(sf::Time frameTime);

        void addFrame(sf::IntRect frame);
        void play();
        void restart();
        void pause();
        void unpause();
        sf::Sprite currentSprite();
    };
}

#endif // DS_ANIMATION_HPP
