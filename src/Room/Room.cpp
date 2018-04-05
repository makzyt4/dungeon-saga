#include "../../include/Room/Room.hpp"

void ds::Room::setPosition(const sf::Vector2i& position) {
    this->position.x = position.x * 16;
    this->position.y = position.x * 16;
}
