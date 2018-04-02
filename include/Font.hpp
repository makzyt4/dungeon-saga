#ifndef DS_FONT_HPP
#define DS_FONT_HPP

#include <map>
#include <array>
#include "ResourceLoader.hpp"

namespace ds {
    class Font {
    private:
        std::map<char, std::uint64_t> charMap;

    public:
        Font();

        std::uint64_t getChar(char c);
    };
}

#endif
