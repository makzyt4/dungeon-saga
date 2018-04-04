#ifndef DS_GAME_LEVEL_HPP
#define DS_GAME_LEVEL_HPP

#include "../Character/PlayerCharacter.hpp"
#include "../Block/BlockBrick.hpp"

namespace ds {
    class Level : public DrawableObject, public Updatable {
    private:
        PlayerCharacter* player;
        std::vector<std::vector<Block*>> blocks;
    public:
        Level(const std::size_t& width, const std::size_t& height);

        void setPlayer(PlayerCharacter* player);
        void addBlock(Block* block, const size_t& x, const size_t& y);
    };
}

#endif // DS_GAME_LEVEL_HPP
