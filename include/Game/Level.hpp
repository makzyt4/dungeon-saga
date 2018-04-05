#ifndef DS_GAME_LEVEL_HPP
#define DS_GAME_LEVEL_HPP

#include <algorithm>
#include "../Character/PlayerCharacter.hpp"
#include "../Block/BlockBrick.hpp"

namespace ds {
    class Level : public DrawableObject, public Updatable {
    private:
        PlayerCharacter* player;
        std::vector<Block*> blocks;
    public:
        Level(const std::uint8_t& difficulty);

        void setPlayer(PlayerCharacter* player);
        void addBlock(Block* block, const size_t& x, const size_t& y);
        void update();
        void draw();
    };
}

#endif // DS_GAME_LEVEL_HPP
