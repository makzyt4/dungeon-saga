#ifndef DS_GAME_ELEMENT_ARRAY_HPP
#define DS_GAME_ELEMENT_ARRAY_HPP

#include <vector>
#include "Block.hpp"

namespace ds {
    class GameElementArray {
    private:
        std::vector<Block*> blocks;

    public:
        void addBlock(Block* block);
        void drawAll(sf::RenderWindow* window);
    };
}

#endif // DS_GAME_ELEMENT_ARRAY_HPP
