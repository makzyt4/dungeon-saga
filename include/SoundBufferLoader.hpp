#ifndef DS_SOUND_BUFFER_LOADER_HPP
#define DS_SOUND_BUFFER_LOADER_HPP

#include <iostream>
#include <map>
#include <SFML/Audio.hpp>

namespace ds {
    class SoundBufferLoader {
    private:
        std::map<std::string, sf::SoundBuffer*> soundBufferMap;

    public:
        SoundBufferLoader();
        sf::SoundBuffer* getSoundBuffer(std::string path);
    };
}

#endif // DS_SOUND_BUFFER_LOADER_HPP
