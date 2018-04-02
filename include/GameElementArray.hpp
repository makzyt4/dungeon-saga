#ifndef DS_GAME_ELEMENT_ARRAY_HPP
#define DS_GAME_ELEMENT_ARRAY_HPP

#include <vector>
#include "Block.hpp"

namespace ds {
    class GameElementArray {
    private:
        std::vector<Block*> blocks;

    public:
        std::vector<Block*> getBlocks() const;

        void addBlock(Block* block);
        void drawAll(sf::RenderWindow* window);
    };
}

#endif // DS_GAME_ELEMENT_ARRAY_HPP
