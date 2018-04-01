#ifndef DS_SOUND_LOADER_HPP
#define DS_SOUND_LOADER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

namespace ds {
    class SoundLoader {
    private:
        std::map<std::string, sf::SoundBuffer*> soundMap;
    public:
        SoundLoader();
        sf::SoundBuffer* getSoundBuffer(std::string path);
    };
}

#endif // DS_FONT_LOADER_HPP
