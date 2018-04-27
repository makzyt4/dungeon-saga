#include "../../include/Game/Level.hpp"
#include "../../include/Game/RoomGenerator.hpp"

ds::Level::Level() {
    generator = RoomGenerator(this);
}

void ds::Level::init() {
    bombBuffer = loader->getSoundBuffer("bomb.ogg");
}

void ds::Level::setPlayer(PlayerCharacter* player) {
    this->player = player;
}

void ds::Level::addBlock(ds::Block* block, const std::size_t& x, const std::size_t& y) {
    block->setWindow(window);
    block->setLoader(loader);
    block->init();
    block->setPosition(sf::Vector2f(x * 16, y * 16));

    for (Block* b : blocks) {
        if (block->getRect().intersects(b->getRect())) {
            std::vector<Block*>::iterator position = std::find(blocks.begin(), blocks.end(), b);
            if (position != blocks.end()) {
                blocks.erase(position);
            }
        }
    }

    blocks.push_back(block);
}

void ds::Level::explode(const float& x, const float& y, const float& radius) {
    printf("EXPLOSION\n");

    sf::Sound* bombSound = new sf::Sound();
    bombSound->setBuffer(*bombBuffer);
    bombSound->play();

    for (Block* b : blocks) {
        const float dx = b->getCenter().x - x; 
        const float dy = b->getCenter().y - y; 
     
        const float distance = std::sqrt(dx * dx + dy * dy);

        if (distance > radius) {
            continue;
        }

        b->destroyed = true;
    }
}

void ds::Level::update() {
    if (levelClock.getElapsedTime() > sf::milliseconds(17)) {
        for (Block* b : blocks) {
            b->update();
        }

        for (Bomb* bomb : bombs) {
            bomb->update();

            if (bomb->exploding && !bomb->exploded) {
                explode(bomb->getPosition().x + 8, bomb->getPosition().y + 8, 32);
                bomb->exploded = true;
            }

            if (bomb->explosionEnded) {
                std::vector<Bomb*>::iterator position = std::find(bombs.begin(), bombs.end(), bomb);
                if (position != bombs.end()) {
                    bombs.erase(position);
                }
            }
        }

        player->collide(&blocks);
        player->update();
        levelClock.restart();

        for (Animation effect : effects) {
            effect.play();
        }
    }
}

void ds::Level::draw() {
    const float maxDistance = std::max(window->getSize().x / 2, window->getSize().y / 2);

    for (Block* block : blocks) {
        const float dx = block->getCenter().x - player->getCenter().x; 
        const float dy = block->getCenter().y - player->getCenter().y; 
     
        const float distance = std::sqrt(dx * dx + dy * dy);

        if (distance < maxDistance) {
            block->draw();
        }
    }

    for (Bomb* bomb : bombs) {
        bomb->draw();
    }

    player->draw();
}

void ds::Level::generateLevel(const std::uint8_t& rooms) {
    bool startUp = rand() % 2;
    generator.generateRooms(sf::Vector2i(80, 80), rooms, startUp);
    surroundBlocks();
}

void ds::Level::surroundBlocks() {
    for (Block* block : blocks) {
        if (block->isCollidable()) {
            continue;
        }

        sf::Vector2f point;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                bool clear = true;
                point = block->getCenter();
                point.x += i * block->getRect().width;
                point.y += j * block->getRect().height;

                for (Block* block2 : blocks) {
                    if (block == block2) {
                        continue;
                    }

                    if (block2->getRect().contains(point.x, point.y)) {
                        clear = false;
                        break;
                    }
                }

                if (clear) {
                    addBlock(new BlockBrick(), block->getRect().left / 16 + i, block->getRect().top / 16 + j);
                }
            }
        }
    }
}

bool ds::Level::isSpaceAvailable(const sf::IntRect& rect) {
    for (Block* block : blocks) {
        if (rect.intersects(block->getRect())) {
            return false;
        }
    }

    return true;
}
