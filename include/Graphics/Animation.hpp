#ifndef DS_GRAPHICS_ANIMATION_HPP
#define DS_GRAPHICS_ANIMATION_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "../System/Timer.hpp"

namespace ds {
    class Animation {
    private:
        bool paused;
        bool looped;
        std::size_t frameIndex;

        ds::Timer timer;
        sf::Time frameTime;
        sf::Texture* spriteSheet;
        std::vector<sf::IntRect> frames;
    public:
        Animation();
        Animation(const sf::Time& frameTime);
        Animation(const sf::Time& frameTime, const bool& looped);
        Animation(const sf::Time& frameTime, const bool& looped,
                  const bool& paused);

        bool isPaused() const;
        bool isLooped() const;
        sf::Time getFrameTime() const;

        void setSpriteSheet(sf::Texture* spriteSheet);
        void setFrameTime(const sf::Time& frameTime);

        void addFrame(const sf::IntRect& frame);
        void play();
        void restart();
        void pause();
        void unpause();
        sf::Sprite currentSprite();
    };
}

#endif // DS_GRAPHICS_ANIMATION_HPP
