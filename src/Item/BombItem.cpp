#include "../../include/Item/BombItem.hpp"

void ds::BombItem::init() {
    type = ds::ItemType::BOMB;
    name = "Bomb";

    sf::Texture* texture = loader->getTexture("items.png");
    sprite.setPosition(rect.left, rect.top);
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
}