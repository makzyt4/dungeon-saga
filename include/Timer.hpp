#ifndef DS_TIMER_HPP
#define DS_TIMER_HPP

#include <SFML/System.hpp>

namespace ds {
    class Timer {
    private:
        sf::Clock clock;
        sf::Time elapsedTime;

        bool running;
    public:
        Timer();

        sf::Time getElapsedTime();
        bool isRunning();

        void update();
        void stop();
        void restart();
        void unpause();
        void pause();
    };
}

#endif
