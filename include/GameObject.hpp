#ifndef DS_GAME_OBJECT_HPP
#define DS_GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Updatable.hpp"

namespace ds {
    class GameObject : public Updatable {
    protected:
        sf::IntRect rect;

    public:
        sf::IntRect getRect() const;
    };
}

#endif // DS_GAME_OBJECT_HPP
