#include "../../include/Game/Level.hpp"
#include "../../include/Game/RoomGenerator.hpp"

ds::Level::Level() {
    generator = RoomGenerator(this);
}

void ds::Level::setPlayer(PlayerCharacter* player) {
    this->player = player;
}

void ds::Level::addBlock(ds::Block* block, const std::size_t& x,
                         const std::size_t& y) {
    block->setWindow(window);
    block->setLoader(loader);
    block->init();
    block->setPosition(sf::Vector2f(x * 16, y * 16));

    for (Block* b : blocks) {
        if (block->getRect().intersects(b->getRect())) {
            std::vector<Block*>::iterator position = std::find(blocks.begin(),
                                                               blocks.end(), b);
            if (position != blocks.end()) {
                blocks.erase(position);
            }
        }
    }

    blocks.push_back(block);
}

void ds::Level::update() {
    for (Block* b : blocks) {
        b->update();
    }
    player->collide(&blocks);
    player->update();
}

void ds::Level::draw() {
    for (Block* block : blocks) {
        block->draw();
    }
    player->draw();
}

void ds::Level::generateLevel() {
    bool startUp = rand() % 2;
    generator.generateRooms(sf::Vector2i(80, 80), 10, startUp);
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
                    addBlock(new BlockBrick(), block->getRect().left / 16 + i,
                                               block->getRect().top / 16 + j);
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
